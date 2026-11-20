# Local passwords

On a prepared VM, the first `make` generates four random files with owner-only permissions. Subsequent runs reuse them. Back them up privately. Git ignores `secrets/*.txt`.

| File | Who reads it |
| --- | --- |
| `db_root_password.txt` | MariaDB, for the local database administrator |
| `db_password.txt` | MariaDB and WordPress, for the application database account |
| `wp_admin_password.txt` | WordPress, for the initial site administrator |
| `wp_author_password.txt` | WordPress, for the initial author |

Compose exposes a file only to the listed services, at `/run/secrets/<name>` without the `.txt` suffix. NGINX gets no secret file. If you supply your own database passwords, use one nonempty line of letters, numbers, underscores or hyphens. The generated 48-character hexadecimal values meet this rule.

For an existing installation, restore the original files before starting. Account and database password changes are covered in the user and developer documents.
