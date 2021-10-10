main: main.o funcs.o
	g++ -o main main.o funcs.o

tests: tests.o funcs.o caesar.o
	g++ -o tests tests.o funcs.o

test-ascii: test-ascii.o
	g++ -o test-ascii test-ascii.o


funcs.o: funcs.cpp funcs.h
	g++ -c funcs.cpp

main.o: main.cpp funcs.h
	g++ -c main.cpp

tests.o: tests.cpp doctest.h funcs.h caesar.h
	g++ -std=c++11 -c tests.cpp

test-ascii.o: test-ascii.cpp
	g++ -c test-ascii.cpp

clean:
	rm -f main main.o funcs.o tests.o test-ascii.o
