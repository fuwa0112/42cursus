#!/bin/sh
set -eu

wp_cli() {
    runuser -u www-data -- wp "$@"
}

admin=$(printf '%s' "$WP_ADMIN_USER" | tr '[:upper:]' '[:lower:]')
author=$(printf '%s' "$WP_AUTHOR_USER" | tr '[:upper:]' '[:lower:]')
case "$admin" in
    ""|*admin*) echo "Choose a WordPress administrator name without 'admin'." >&2; exit 1 ;;
esac
if [ -z "$author" ] || [ "$admin" = "$author" ]; then
    echo "Choose two different WordPress usernames." >&2
    exit 1
fi

# Docker copies the image's WordPress files into the empty named volume.
if [ ! -s wp-config.php ]; then
    chown www-data:www-data .
    wp_cli config create --dbname="$DB_NAME" --dbuser="$DB_USER" --dbhost=mariadb \
        --skip-check --prompt=dbpass < /run/secrets/db_password
    chmod 640 wp-config.php
fi

if ! wp_cli core is-installed; then
    wp_cli core install --url="https://${DOMAIN_NAME}" --title="$WP_SITE_TITLE" \
        --admin_user="$WP_ADMIN_USER" --admin_email="$WP_ADMIN_EMAIL" \
        --skip-email --prompt=admin_password < /run/secrets/wp_admin_password
fi

if ! wp_cli user get "$WP_AUTHOR_USER" --field=ID >/dev/null 2>&1; then
    wp_cli user create "$WP_AUTHOR_USER" "$WP_AUTHOR_EMAIL" --role=author \
        --prompt=user_pass < /run/secrets/wp_author_password
fi

sed -i "s|^listen = .*|listen = ${FPM_PORT}|" /etc/php/8.2/fpm/pool.d/www.conf
exec php-fpm8.2 -F
