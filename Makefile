up:
	@PODMAN_COMPOSE_WARNING_LOGS=false podman compose up -d --build --remove-orphans

down:
	@PODMAN_COMPOSE_WARNING_LOGS=false podman compose down

shell:
	@PODMAN_COMPOSE_WARNING_LOGS=false podman compose exec sandbox-c bash
