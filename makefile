CC = g++
CFLAGS = -g -Wall
LFLAGS = -L/usr/lib

all:assigment1

assigment1: bin/main.o bin/cyberpc.o bin/cyberdns.o bin/xml_parser.o bin/cyberworm.o
	$(CC) -o bin/main bin/main.o bin/cyberpc.o bin/cyberdns.o bin/xml_parser.o bin/cyberworm.o $(LFLAGS)

bin/main.o: main.cpp
	$(CC) $(CFLAGS) -c -Lincluse -o bin/main.o main.cpp

bin/cyberdns.o: src/cyberdns.cpp
	$(CC) $(CFLAGS) -c -Lincluse -o bin/cyberdns.o src/cyberdns.cpp

bin/cyberpc.o: src/cyberpc.cpp
	$(CC) $(CFLAGS) -c -Lincluse -o bin/cyberpc.o src/cyberpc.cpp

bin/cyberworm.o: src/cyberworm.cpp
	$(CC) $(CFLAGS) -c -Lincluse -o bin/cyberworm.o src/cyberworm.cpp

	
bin/xml_parser.o: src/xml_parser.cpp
	$(CC) $(CFLAGS) -c -Linclude -I/usr/local/boost/1.57.0/include/boost -o bin/xml_parser.o src/xml_parser.cpp

	
	
clean:
	rm -f bin/*