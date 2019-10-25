wzip: wzip.o
	gcc -o wzip wzip.o -lm
wzip.o: wzip.c
	gcc -O -Wall -Werror -c wzip.c
clean:
	rm -f wzip.o