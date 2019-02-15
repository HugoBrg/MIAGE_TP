all : main.o queue.o
	gcc main.o queue.o -o queue -lm

queue.o : queue.c queue.h
	gcc -c queue.c

main.o : main.c
	gcc -c main.c

clean:
	rm *.o queue

