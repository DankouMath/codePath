all: main
	./0x06.o

binarytree.o: binarytree.c
	gcc -c binarytree.c -o binarytree.o

main.o: main.c
	gcc -c main.c -o main.o


main: binarytree.o main.o
	gcc *.o -o 0x06.o

clean:
	rm *.o
