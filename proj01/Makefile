project=TerminalStack

CC = g++
FLAGS = -std=c++11 -Wall -g

all: terminal

terminal: main.o terminal.o
	$(CC) $(FLAGS) -o $(project) main.o terminal.o

terminal.o: Terminal.cpp Terminal.h Stack.h
	$(CC) $(FLAGS) -c Terminal.cpp -o terminal.o

main.o: main.cpp
	$(CC) $(FLAGS) -c main.cpp -o main.o

test:
	cp -f Terminal.cpp Stack.h tests/src; \
	cd ./tests; \
	cmake CMakeLists.txt; \
	make && ./RunStacksProjectTests; \
	cd .. ; \

clean:
	rm -f *.o
	rm -f *.gch
	rm -f $(project)

	cd ./tests; \
	./cmake_clean; \
	cd .. ; \

