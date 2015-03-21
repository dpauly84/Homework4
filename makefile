CC=g++ -Wall

all: parts4

parts4: utils.o sllist.o parts4.hpp parts4.cpp
	$(CC) -o parts4 parts4.cpp sllist.o utils.o

sllist.o: sllist.hpp sllist.cpp
	$(CC) -c sllist.cpp

utils.o: utils.hpp utils.cpp
	$(CC) -c utils.cpp

tidy :
	rm -f utils.o sllist.o core

clean :
	rm -f parts4 utils.o sllist.o core
