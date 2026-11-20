include srcs/.env

COMPOSE = docker compose --env-file srcs/.env -f srcs/docker-compose.yml
SECRETS = db_root_password db_password wp_admin_password wp_author_password

.PHONY: all up down ps logs check-storage secrets

all: up

up: check-storage secrets
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

logs:
	$(COMPOSE) logs --follow
