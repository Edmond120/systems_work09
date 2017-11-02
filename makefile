all: dirinfo.c
	gcc -o dirinfo dirinfo.c

run: all
	./dirinfo

clean:
	rm dirinfo
