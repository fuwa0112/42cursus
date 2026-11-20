# Using the WordPress site

NGINX serves the HTTPS website. WordPress runs the public pages and the editing dashboard. MariaDB stores the text, comments, accounts and settings.

## Start and stop

On the prepared VM, open a terminal in the folder containing the Makefile. First-time VM setup is in [DEV_DOC.md](DEV_DOC.md).

| Command | Result |
| --- | --- |
| `make` | Build and start the site. A new site gets four random passwords. Future starts reuse them. |
| `make ps` | Show the three services and the port mapping. MariaDB and NGINX should be healthy. WordPress should be running. |
| `make logs` | Follow recent service messages. Ctrl+C closes the log viewer. |
| `make down` | Stop and remove the containers. Both named volumes keep their data. |

## Visit and sign in

Open `https://thitoe.42.fr/` in a browser that resolves this name to the project VM. The certificate is self-signed. After checking that the address is your VM, accept the local certificate warning if prompted.

Open `https://thitoe.42.fr/wp-admin/` to sign in. WordPress provides the login form and dashboard.

| Account | Use | Local password file |
| --- | --- | --- |
| `siteowner` | Administrator. Edit pages, manage users and approve comments. | `secrets/wp_admin_password.txt` |
| `writer` | Author. Publish their own posts and leave comments on open posts. | `secrets/wp_author_password.txt` |

In your private VM terminal, read the single file for the account you need, for example `cat secrets/wp_author_password.txt`. Keep passwords off shared screens. The usernames are configured in `srcs/.env`. The two database passwords are for database clients.

## Try it

1. Sign in as `writer`. On the public site open the individual **Hello world!** post and submit a comment. If it awaits moderation, approve it under **Comments** as `siteowner`.
2. As `siteowner`, open **Pages → All Pages → Sample Page**. Edit a sentence, save it and open **View Page** to verify the change on the public site.
3. After `make down` and `make`, revisit the same post and page. For the defense, also repeat the check after a VM reboot.

## Manage credentials

Keep a private backup of the four files in `secrets/` together with the data backups. To change a WordPress login password, use the account's profile in the dashboard, then update its private local password file to match. Changing a file alone does not change an existing WordPress account. Database credential management is covered in [DEV_DOC.md](DEV_DOC.md).

If the browser cannot find the domain, check the hosts file on the machine running that browser. For a connection error or a 502 response, start with `make ps` and `make logs`.
