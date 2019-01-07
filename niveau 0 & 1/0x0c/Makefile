ppm.o: ppm.c
	gcc -c ppm.c

main.o: main.c
	gcc -c main.c

main: ppm.o main.o 
	gcc -g *.o -o bezier

clean:
	rm *.o
	rm bezier
	
