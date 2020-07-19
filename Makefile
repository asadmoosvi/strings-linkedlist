all: test

test: test.o linkedlist.o
	gcc -o test test.o linkedlist.o

test.o: test.c linkedlist.h
	gcc -c test.c

linkedlist.o: linkedlist.c linkedlist.h
	gcc -c linkedlist.c

clean:
	$(RM) test *.o
