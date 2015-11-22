CC = g++
CFLAGS = -g -Wall
LFLAGS = -L/usr/lib

all:assigment1

assigment1: bin/main.o bin/cyberpc.o bin/cyberdns.o bin/simulation.o bin/cyberworm.o bin/cyberexpert.o
	$(CC) -o bin/cyber bin/main.o bin/cyberpc.o bin/cyberdns.o bin/simulation.o bin/cyberworm.o bin/cyberexpert.o $(LFLAGS)

bin/main.o: src/main.cpp
	$(CC) $(CFLAGS) -c -Lincluse -o bin/main.o src/main.cpp

bin/cyberdns.o: src/cyberdns.cpp
	$(CC) $(CFLAGS)	-c -Lincluse -o bin/cyberdns.o src/cyberdns.cpp

bin/cyberpc.o: src/cyberpc.cpp
	$(CC) $(CFLAGS)	-c -Lincluse -o bin/cyberpc.o src/cyberpc.cpp

bin/cyberworm.o: src/cyberworm.cpp
	$(CC) $(CFLAGS)	-c -Lincluse -o bin/cyberworm.o src/cyberworm.cpp

bin/cyberexpert.o: src/cyberexpert.cpp
	$(CC) $(CFLAGS)	-c -Lincluse -o bin/cyberexpert.o src/cyberexpert.cpp

bin/simulation.o: src/simulation.cpp
	$(CC) $(CFLAGS)	-c -Linclude -I/usr/local/boost/1.57.0/include/boost -o bin/simulation.o src/simulation.cpp


	
clean:
	rm -f bin/*