
CC = gcc
CFLAG= -Wall -g

all: linktest

SingleLinkedList.o: SingleLinkedList.c SingleLinkedList.h
	$(CC) $(CFLAG) -c SingleLinkedList.c

linktest: linktest.c SingleLinkedList.dll
	$(CC) $(CFLAG) -o $@ $^

rough: rough.c
	$(CC) $(CFLAG) -o $@ $^

clean:
	del *.exe Main rough
	#del *.o SingleLinkedList

SingleLinkedList.dll: SingleLinkedList.c
	$(CC) $(CFLAG) -shared -fPIC -o $@ $^

SingleLinkedList.a: SingleLinkedList.o
	ar rcs $@ $^