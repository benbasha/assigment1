CC = g++
CFLAGS = -g -Wall -Weffc++
LFLAGS = -L/usr/lib

all:assigment1

assigment1: bin/main.o
	$(CC) -o bin/main bin/main.o  $(LFLAGS)

bin/main.o: main.cpp
	$(CC) $(CFLAGS) -c -Lincluse -o bin/main.o main.cpp


clean:
	rm -f bin/*