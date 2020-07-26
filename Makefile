all: test test2

test: test.o linkedlist.o
	gcc -o test test.o linkedlist.o

test.o: test.c linkedlist.h
	gcc -c test.c

test2: test2.o linkedlist.o
	gcc -o test2 test2.o linkedlist.o

test2.o: test2.c linkedlist.h
	gcc -c test2.c

linkedlist.o: linkedlist.c linkedlist.h
	gcc -c linkedlist.c

clean:
	$(RM) test test2 *.o
