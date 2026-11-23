include srcs/.env

COMPOSE = docker compose --env-file srcs/.env -f srcs/docker-compose.yml
SECRETS = db_root_password db_password wp_admin_password wp_author_password

.PHONY: all up down ps logs check-storage secrets reset

all: up

up: secrets
	$(COMPOSE) up -d --build --wait

check-storage:
	@root=$$(docker info --format '{{.DockerRootDir}}') || exit 1; \
	case "$$root" in \
	  /home/$(LOGIN)/data|/home/$(LOGIN)/data/*) ;; \
	  *) echo "Set Docker's data-root under /home/$(LOGIN)/data on the project VM. See DEV_DOC.md."; exit 1 ;; \
	esac

secrets:
	@set -euC; umask 077; \
	volumes=$$(docker volume ls --format '{{.Name}}'); \
	for name in $(SECRETS); do \
	  file="secrets/$$name.txt"; \
	  if [ -s "$$file" ]; then continue; fi; \
	  if printf '%s\n' "$$volumes" | grep -Eq '^inception_(database|wordpress)$$'; then \
	    echo "Existing site: restore $$file from your private backup before starting."; exit 1; \
	  fi; \
	  value=$$(openssl rand -hex 24); \
	  printf '%s\n' "$$value" > "$$file"; \
	done

down:
	$(COMPOSE) down

ps:
	$(COMPOSE) ps

reset:
	@set -eu; \
	set --; \
	for vol in inception_database inception_wordpress inception_mariadb_data inception_wordpress_data; do \
		if docker volume inspect "$$vol" >/dev/null 2>&1; then \
			device=$$(docker volume inspect -f '{{if .Options}}{{index .Options "device"}}{{end}}' "$$vol"); \
			if [ -n "$$device" ] && [ "$$device" != "<no value>" ]; then \
				path=$$(realpath -m "$$device"); \
				case "$$path" in \
					"$(HOME)/data/"*) set -- "$$@" "$$path" ;; \
					*) echo "Unsafe volume path: $$path"; exit 1 ;; \
				esac; \
			fi; \
		fi; \
	done; \
	$(COMPOSE) down -v --remove-orphans; \
	for name in inception-mariadb-1 inception-wordpress-1 inception-nginx-1; do \
		if docker container inspect "$$name" >/dev/null 2>&1; then \
			docker rm -f "$$name"; \
		fi; \
	done; \
	for vol in inception_database inception_wordpress inception_mariadb_data inception_wordpress_data; do \
		if docker volume inspect "$$vol" >/dev/null 2>&1; then \
			docker volume rm "$$vol"; \
		fi; \
	done; \
	for img in mariadb:inception wordpress:inception nginx:inception; do \
		if docker image inspect "$$img" >/dev/null 2>&1; then \
			docker image rm "$$img"; \
		fi; \
	done; \
	for dir in "$$@"; do \
		if [ -d "$$dir" ]; then \
			find "$$dir" -mindepth 1 -maxdepth 1 -exec rm -rf -- {} +; \
		fi; \
	done; \
	rm -f secrets/db_root_password.txt secrets/db_password.txt \
	      secrets/wp_admin_password.txt secrets/wp_author_password.txt; \
	echo "Inception reset complete."


logs:
	$(COMPOSE) logs --follow
