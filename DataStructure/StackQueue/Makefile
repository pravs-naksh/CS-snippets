all:main

dlinklist.o: dlinklist.h dlinklist.c
	gcc -Wall -g -c dlinklist.c

queue.o: queue.h queue.c
	gcc -Wall -g -c queue.c

stack.o: stack.h stack.c
	gcc -Wall -g -c stack.c

postfix.o: postfix.h postfix.c
	gcc -Wall -g -c postfix.c

main.o: main.c
	gcc -Wall -g -c main.c

main: dlinklist.o queue.o stack.o postfix.o main.o
	gcc -Wall -g dlinklist.o queue.o stack.o postfix.o main.o -o main

clean:
	rm *.o main
