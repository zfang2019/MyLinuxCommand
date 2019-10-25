wgrep: wgrep.o
	gcc -o wgrep wgrep.o -lm
wgrep.o: wgrep.c
	gcc -O -Wall -Werror -c wgrep.c
clean:
	rm -f wgrep.o
	rm -rf tests-out