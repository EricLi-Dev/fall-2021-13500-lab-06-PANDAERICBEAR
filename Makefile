main: main.o funcs.o
	g++ -o main main.o funcs.o

tests: tests.o funcs.o caesar.o vigenere.o decrypt.o
	g++ -o tests tests.o funcs.o caesar.o vigenere.o decrypt.o

test-ascii: test-ascii.o
	g++ -o test-ascii test-ascii.o


funcs.o: funcs.cpp funcs.h
	g++ -c funcs.cpp

main.o: main.cpp funcs.h
	g++ -c main.cpp

tests.o: tests.cpp doctest.h funcs.h caesar.h vigenere.h decrypt.h
	g++ -std=c++11 -c tests.cpp

test-ascii.o: test-ascii.cpp
	g++ -c test-ascii.cpp

clean:
	rm -f tests main test-ascii main.o funcs.o tests.o test-ascii.o caesar.o vigenere.o decrypt.o
