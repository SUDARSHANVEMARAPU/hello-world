
CC=gcc
CFLAG=-Wall -g

all: Main

Arraylist.o: Arraylist.c structure.h
	$(CC) $(CFLAG) -c Arraylist.c

Main: Main.c Arraylist.dll structure.h
	$(CC) $(CFLAG) -o $@ Main.c -L. Arraylist.dll

clean: 
	del *.o Arraylist
	del *.exe Main

rough: rough.c
	$(CC) $(CFLAG) -o $@ $^

Arraylist.a: Arraylist.o 
	ar rcs Arraylist.a Arraylist.o	

Arraylist.dll: Arraylist.c
	$(CC) $(CFLAG) -shared -fPIC -o $@ $^ 