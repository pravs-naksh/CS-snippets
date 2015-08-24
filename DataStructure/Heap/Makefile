all:main

dlinklist.o: dlinklist.h dlinklist.c
	gcc -Wall -g -c dlinklist.c

deque.o: deque.h deque.c
	gcc -Wall -g -c deque.c

heap.o: heap.h heap.c
	gcc -Wall -g -c heap.c

heapApp.o: heapApp.h heapApp.c
	gcc -Wall -g -c heapApp.c

main.o: main.c
	gcc -Wall -g -c main.c

main: dlinklist.o deque.o heap.o heapApp.o main.o
	gcc -Wall -g -lm dlinklist.o deque.o heap.o heapApp.o main.o -o main

clean:
	rm *.o *~ main
