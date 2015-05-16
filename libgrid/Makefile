CFLAGS+= -Wall -g -std=c99 -Wno-unused-variable
SRC_FILES=src/grid.c src/move.c src/player.c src/point.c

all: mklib mkobj lib/libgrid.a

mklib:
	-@mkdir -p lib

mkobj:
	-@mkdir -p obj

lib/libgrid.a: obj/grid.o obj/move.o obj/player.o obj/point.o
	ar -crv $@ $^

obj/%.o: src/%.c
	gcc -c $^ -o $@ -Iinclude $(CFLAGS)

clean:
	-@rm -rf lib
	-@rm -rf obj

depend:
	makedepend -- $(CFLAGS) -- $(SRC_FILES)
