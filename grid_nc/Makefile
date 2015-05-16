CFLAGS+= -Wall -g -std=c99
APP_NAME=grid_nc
LD_FLAGS=-lgrid -lncurses -L../libgrid/lib
INCLUDES=-I../libgrid/include
OBJ_FILES=obj/main_nc.o obj/play.o
SRC_FILES=src/main_nc.c src/play.c

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
# DO NOT DELETE

src/main_nc.o: /usr/include/curses.h /usr/include/ncurses_dll.h
src/main_nc.o: /usr/include/stdint.h /usr/include/features.h
src/main_nc.o: /usr/include/stdc-predef.h /usr/include/sys/cdefs.h
src/main_nc.o: /usr/include/bits/wordsize.h /usr/include/gnu/stubs.h
src/main_nc.o: /usr/include/bits/wchar.h /usr/include/stdio.h
src/main_nc.o: /usr/include/bits/types.h /usr/include/bits/typesizes.h
src/main_nc.o: /usr/include/libio.h /usr/include/_G_config.h
src/main_nc.o: /usr/include/wchar.h /usr/include/bits/stdio_lim.h
src/main_nc.o: /usr/include/bits/sys_errlist.h /usr/include/unctrl.h
src/main_nc.o: src/play.h
src/play.o: /usr/include/curses.h /usr/include/ncurses_dll.h
src/play.o: /usr/include/stdint.h /usr/include/features.h
src/play.o: /usr/include/stdc-predef.h /usr/include/sys/cdefs.h
src/play.o: /usr/include/bits/wordsize.h /usr/include/gnu/stubs.h
src/play.o: /usr/include/bits/wchar.h /usr/include/stdio.h
src/play.o: /usr/include/bits/types.h /usr/include/bits/typesizes.h
src/play.o: /usr/include/libio.h /usr/include/_G_config.h
src/play.o: /usr/include/wchar.h /usr/include/bits/stdio_lim.h
src/play.o: /usr/include/bits/sys_errlist.h /usr/include/unctrl.h src/play.h
