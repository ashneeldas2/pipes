all: quickmaths.c
	gcc -o quickmaths quickmaths.c
run: quickmaths
	./quickmaths
