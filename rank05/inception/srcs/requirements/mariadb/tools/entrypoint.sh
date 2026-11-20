#!/bin/sh
set -eu

DATADIR=/var/lib/mysql
SOCKET=/run/mysqld/mysqld.sock
INIT_FILE=/run/mysqld/init.sql

check_identifier() {
    case "$1" in
        ""|*[!A-Za-z0-9_]*) echo "Invalid database identifier" >&2; exit 1 ;;
    esac
}

check_secret() {
    case "$1" in
        ""|*CHANGE_ME*|*[!A-Za-z0-9_-]*) echo "Secret is empty or contains unsupported characters" >&2; exit 1 ;;
    esac
}

check_identifier "$DB_NAME"
check_identifier "$DB_USER"
root_password=$(cat /run/secrets/db_root_password)
db_password=$(cat /run/secrets/db_password)
check_secret "$root_password"
check_secret "$db_password"

mkdir -p /run/mysqld "$DATADIR"
chown mysql:mysql /run/mysqld "$DATADIR"

if [ ! -d "$DATADIR/mysql" ]; then
    mariadb-install-db --user=mysql --datadir="$DATADIR" \
        --auth-root-authentication-method=socket --skip-test-db
fi

umask 077
cat > "$INIT_FILE" <<SQL
ALTER USER 'root'@'localhost' IDENTIFIED BY '${root_password}';
CREATE DATABASE IF NOT EXISTS \`${DB_NAME}\` CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci;
CREATE USER IF NOT EXISTS '${DB_USER}'@'%' IDENTIFIED BY '${db_password}';
ALTER USER '${DB_USER}'@'%' IDENTIFIED BY '${db_password}';
GRANT ALL PRIVILEGES ON \`${DB_NAME}\`.* TO '${DB_USER}'@'%';
SQL
chown mysql:mysql "$INIT_FILE"

exec mariadbd --user=mysql --datadir="$DATADIR" --socket="$SOCKET" \
    --init-file="$INIT_FILE"
