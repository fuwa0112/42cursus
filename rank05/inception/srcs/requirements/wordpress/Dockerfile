FROM debian:12-slim

ARG WORDPRESS_VERSION=7.1.5
ARG WP_CLI_VERSION=2.12.0

RUN apt-get update \
    && DEBIAN_FRONTEND=noninteractive apt-get install -y --no-install-recommends \
       ca-certificates curl php8.2-cli php8.2-fpm php8.2-mysql php8.2-curl \
       php8.2-gd php8.2-mbstring php8.2-xml php8.2-zip php8.2-intl \
    && rm -rf /var/lib/apt/lists/*

WORKDIR /var/www/html
RUN mkdir -p /run/php \
    && curl -fsSLo /tmp/wordpress.tar.gz \
       "https://wordpress.org/wordpress-${WORDPRESS_VERSION}.tar.gz" \
    && tar -xzf /tmp/wordpress.tar.gz --strip-components=1 -C /var/www/html \
    && rm /tmp/wordpress.tar.gz \
    && chown -R www-data:www-data /var/www/html \
    && curl -fsSLo /usr/local/bin/wp \
       "https://github.com/wp-cli/wp-cli/releases/download/v${WP_CLI_VERSION}/wp-cli-${WP_CLI_VERSION}.phar" \
    && chmod 755 /usr/local/bin/wp

COPY tools/entrypoint.sh /usr/local/bin/entrypoint.sh
RUN chmod 755 /usr/local/bin/entrypoint.sh

ENTRYPOINT ["/usr/local/bin/entrypoint.sh"]
