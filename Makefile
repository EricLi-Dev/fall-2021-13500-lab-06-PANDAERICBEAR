main: main.o caesar.o
	g++ -o main main.o caesar.o

tests: tests.o caesar.o vigenere.o decrypt.o
	g++ -o tests tests.o caesar.o vigenere.o decrypt.o

test-ascii: test-ascii.o
	g++ -o test-ascii test-ascii.o


main.o: main.cpp
	g++ -c main.cpp

tests.o: tests.cpp doctest.h caesar.h vigenere.h decrypt.h
	g++ -std=c++11 -c tests.cpp

test-ascii.o: test-ascii.cpp
	g++ -c test-ascii.cpp

clean:
	rm -f tests main test-ascii main.o tests.o test-ascii.o caesar.o vigenere.o decrypt.o
