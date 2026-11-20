*This project has been created as part of the 42 curriculum by thitoe.*

# Inception

## Description

This project runs a WordPress site inside a Linux virtual machine. Docker Compose builds three images from Debian 12 and starts one container per service. NGINX accepts HTTPS on port 443. It serves static files and forwards PHP requests to PHP-FPM in the WordPress container. WordPress reads and writes posts, comments, accounts and settings in MariaDB.

### Project sources

| File or directory | Purpose |
| --- | --- |
| `Makefile` | Build, start, inspect and stop the stack |
| `srcs/docker-compose.yml` | Declare the three services, their network, their secrets and two named volumes |
| `srcs/.env` | Set the domain, account names and PHP-FPM port |
| `srcs/requirements/` | Provide each service's Dockerfile, startup script and configuration |
| `secrets/` | Hold private password files created locally |
| `USER_DOC.md`, `DEV_DOC.md` | Explain everyday use and first-time VM setup |

### Design choices

| Comparison | How it applies here |
| --- | --- |
| Virtual machines vs Docker | The VM has its own Linux kernel. The containers share that kernel while running isolated processes. |
| Secrets vs environment variables | Environment variables carry settings such as the domain. Compose mounts the password files only in the services that need them. |
| Docker network vs host network | A dedicated bridge provides service-name lookup and container network isolation. Host networking would share the VM's network namespace. Only NGINX publishes a port. |
| Docker volumes vs bind mounts | Docker manages the two named volumes and their lifetimes. A bind mount would expose a specific host path directly. On the project VM, Docker's data root places the volumes under `/home/thitoe/data/`. |

## Instructions

1. Prepare a dedicated Linux VM with Docker Engine, the Compose plugin, Make and OpenSSL. Follow the one-time storage and hostname setup in [DEV_DOC.md](DEV_DOC.md).
2. From the project root run `make`. It generates the four passwords for a new site, builds the images and waits for the HTTPS login page.
3. Open `https://thitoe.42.fr/`. The dashboard is at `https://thitoe.42.fr/wp-admin/`. The VM uses a self-signed certificate.
4. Use `make ps` for status, `make logs` for logs and `make down` to stop. Another `make` reuses your site data. See [USER_DOC.md](USER_DOC.md).

## Resources

- Docker Engine installation and storage. [Debian installation](https://docs.docker.com/engine/install/debian/) · [Daemon configuration](https://docs.docker.com/engine/daemon/) · [Volumes](https://docs.docker.com/engine/storage/volumes/)
- Docker Compose. [Service reference](https://docs.docker.com/reference/compose-file/services/) · [Startup order](https://docs.docker.com/compose/how-tos/startup-order/)
- Distribution and application references. [Debian releases](https://www.debian.org/releases/) · [NGINX FastCGI](https://nginx.org/en/docs/http/ngx_http_fastcgi_module.html) · [PHP-FPM](https://www.php.net/manual/en/install.fpm.configuration.php)
- Site and database tools. [WordPress](https://wordpress.org/documentation/) · [WP-CLI](https://developer.wordpress.org/cli/commands/) · [MariaDB](https://mariadb.com/docs/server/)

AI helped draft and review the Compose file, Dockerfiles, startup scripts and documentation. It helped compare the project with the subject and design configuration checks. The peer evaluation includes explaining the implementation, changing a service and demonstrating it on the VM.
