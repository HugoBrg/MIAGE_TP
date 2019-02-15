all : main.o wav.o
	gcc main.o wav.o -o wav -lm
wav.o : wav.c wav.h
	gcc -c wav.c

main.o : main.c
	gcc -c main.c

clean:
	rm *.o wav

