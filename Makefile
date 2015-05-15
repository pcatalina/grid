SHELL=/bin/bash 

FOLDERS=libgrid grid_sdl grid_nc
FOLDERS_TESTS=libgrid grid_sdl grid_nc
FOLDERS_ALL=${FOLDERS} ${FOLDERS_TESTS}

# call make <target> for each folder (non recursive)
define make_folders
	@for a in $1; do    \
		if [ -d $$a ]; then     \
			$(MAKE) $2 -C $$a;  \
		fi;                     \
	done;
endef


all:
	$(call make_folders, ${FOLDERS}, all)

clean:
	$(call make_folders, ${FOLDERS_ALL}, clean)

docs:
	$(call make_folders, ${FOLDERS}, docs)

tests:
	$(call make_folders, ${FOLDERS_TESTS}, all)
