all: main

binarytree.o: binarytree.c
	gcc -c binarytree.c -o binarytree.o

main.o: main.c
	gcc -c main.c -o main.o


main: binarytree.o main.o
	gcc -g *.o -o 0x09

test: main
	./0x09 "5+9*7"
clean:
	rm *.o
	rm 0x09
