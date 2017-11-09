all: signal.o 
	gcc -o test signal.o

signal.o: signal.c
	gcc -c signal.c

run: all
	./test
 