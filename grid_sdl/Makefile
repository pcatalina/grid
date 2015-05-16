CFLAGS+= -Wall -g -std=c99 $(shell pkg-config --cflags --libs sdl cairo SDL_image)
APP_NAME=grid_sdl
LD_FLAGS=-lgrid -L../libgrid/lib
INCLUDES=-I../libgrid/include
OBJ_FILES=obj/main_sdl.o obj/play_sdl.o
SRC_FILES=src/main_sdl.c src/play_sdl.c

all: mkbin mkobj bin/$(APP_NAME)

mkbin:
	-@mkdir -p bin

mkobj:
	-@mkdir -p obj

bin/$(APP_NAME): $(OBJ_FILES)
	gcc -o $@ $^ $(LD_FLAGS) $(CFLAGS)

obj/%.o: src/%.c
	gcc -c $^ -o $@ $(INCLUDES) $(CFLAGS)

clean:
	-@rm -rf bin
	-@rm -rf obj

depend:
	makedepend -- $(CFLAGS) -- $(SRC_FILES)
