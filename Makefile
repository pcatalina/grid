all:
	make -C libgrid
	make -C grid_sdl
	make -C grid_nc

clean:
	make clean -C libgrid
	make clean -C grid_sdl
	make clean -C grid_nc clean
	-rm -f penguin.tar.gz

archive:
	tar -czvf penguin.tar.gz ./*  --exclude=*.vcxproj*


