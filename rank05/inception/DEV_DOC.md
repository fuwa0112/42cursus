# Developer documentation

## Prepare the VM once

Use a **dedicated Linux VM** with a local, rootful Docker Engine managed by systemd. The Docker CLI must select that VM's Engine. Install a current Compose plugin supporting `up --wait` and `pull_policy: build`, plus Git, Make and OpenSSL. The build downloads Debian packages, WordPress and WP-CLI. The VM user needs permission to run Docker. [Docker Engine on Debian](https://docs.docker.com/engine/install/debian/)

Run these checks on the VM.

```sh
docker info --format '{{.DockerRootDir}}'
docker compose version
make --version
openssl version
```

The two named volumes have to live under `/home/thitoe/data`. Set Docker's `data-root` **on a fresh project VM, before creating the volumes**. This setting applies to the entire daemon. Changing it on an existing Engine can hide its previous volumes and containers. Use a separate VM or perform a planned backup and migration if you have existing work.

```sh
sudo install -d /etc/docker
sudoedit /etc/docker/daemon.json
```

For a new file use this JSON. If the file already has settings, merge the property into the existing JSON object.

```json
{
  "data-root": "/home/thitoe/data/docker"
}
```

```sh
sudo dockerd --validate --config-file=/etc/docker/daemon.json
sudo systemctl restart docker
docker info --format '{{.DockerRootDir}}'
```

Expect `/home/thitoe/data/docker`. A data root equal to `/home/thitoe/data` or inside it also works. The two volume mountpoints will be under that root. [Docker daemon configuration](https://docs.docker.com/engine/daemon/)

Find the VM's local network address with `ip -br -4 address`. Use the network adapter reachable by your browser. Edit `/etc/hosts` on the VM and also on your Mac if you browse from it. Add one line using the actual address, for example:

```text
192.168.64.3 thitoe.42.fr
```

The Mac needs a route to that IP. A hosts entry maps a name to an address. It does not create a route. Use the VM's browser if only the VM can reach that address.

## Build and operate

The directory containing the Makefile is the repository root. If the ZIP was extracted into a wrapper directory, put its contents, including the dotfiles, at the Git root. Review `srcs/.env`; for a different login, adjust the domain, emails, hosts entry and data root consistently.

```sh
make
make ps
docker compose --env-file srcs/.env -f srcs/docker-compose.yml config --quiet
docker compose -f srcs/docker-compose.yml images
docker network inspect inception_inception
docker volume inspect inception_database inception_wordpress
```

`make` checks the storage path, creates missing secret files on a fresh installation, builds all three images, starts the services and waits for the checks. The NGINX check requests the actual WordPress login page over HTTPS and expects HTTP 200. The WordPress files are copied from the image into the empty volume by Docker. NGINX mounts that volume read-only with `nocopy`. On a populated volume Docker keeps the existing files, including the installed core version.

`make down` stops the stack while preserving data. `make` builds again using cached layers. `make logs` follows the logs. To see just one service use `docker compose -f srcs/docker-compose.yml logs --tail=60 wordpress`.

## Accounts and data

| Docker volume | Default mountpoint on this VM | Path inside the container |
| --- | --- | --- |
| `inception_database` | `/home/thitoe/data/docker/volumes/inception_database/_data` | `/var/lib/mysql` in MariaDB |
| `inception_wordpress` | `/home/thitoe/data/docker/volumes/inception_wordpress/_data` | `/var/www/html` in WordPress and NGINX |

The initial four secrets and their scope are listed in [secrets/README.md](secrets/README.md). The DB startup script reapplies the database passwords from its secrets and grants the application account access to the WordPress database. A temporary SQL file lives in the container's memory-backed `/run/mysqld`. WordPress stores its DB connection information in the volume's private `wp-config.php`. Protect volume backups as well as the secrets.

When deliberately rotating the application DB password, coordinate the change to `db_password.txt` and the `DB_PASSWORD` value in `wp-config.php` during downtime, then recreate the services with the updated secret. WordPress account passwords are managed through the dashboard. A fresh checkout that uses an existing installation needs its original secrets.

To inspect data, run these commands from the repository root. Enter the application DB password at the interactive prompt. The last two commands run inside the MariaDB prompt.

```sh
docker compose -f srcs/docker-compose.yml exec -u www-data wordpress wp user list --fields=user_login,roles
docker compose -f srcs/docker-compose.yml exec mariadb mariadb -h 127.0.0.1 -u wp_user -p wordpress
```

```sql
SHOW TABLES;
SELECT user_login FROM wp_users;
```

Type `exit` to return to the shell. For a persistence test, edit a page, add a comment, reboot the **VM**, run `make` and revisit both changes. `docker compose down -v` deletes the named volumes and their data in this project.

An older setup using `/home/thitoe/data/mariadb` and `/home/thitoe/data/wordpress` directly will not automatically appear in these volumes. To retain an existing site, stop the old stack cleanly, back up both data directories and its four secrets, and restore the data to the matching new volumes with owners and modes preserved before the new stack's first start. Use a fresh VM for an independent practice installation.

## Change the PHP-FPM port during the defense

Edit `FPM_PORT=9000` to `FPM_PORT=9001` in `srcs/.env`. Run `make`. The WordPress entrypoint applies the port to the PHP-FPM pool. The NGINX entrypoint renders the same value into its FastCGI destination.

```sh
docker compose -f srcs/docker-compose.yml exec wordpress grep '^listen = ' /etc/php/8.2/fpm/pool.d/www.conf
docker compose -f srcs/docker-compose.yml exec nginx grep fastcgi_pass /etc/nginx/conf.d/default.conf
curl -ksS -o /dev/null -w '%{http_code}\n' https://thitoe.42.fr/wp-login.php
```

Expect the two internal ports to match and HTTPS to return 200. Restore 9000 in the file and run `make` again.
