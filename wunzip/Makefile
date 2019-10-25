wunzip: wunzip.o
	gcc -o wunzip wunzip.o -lm
wunzip.o: wunzip.c
	gcc -O -Wall -Werror -c wunzip.c
clean:
	rm -f wunzip.o
	rm -rf tests-out/