main: main.o caesar.o
	g++ -o main main.o caesar.o

tests: tests.o caesar.o vigenere.o decrypt.o
	g++ -o tests tests.o caesar.o vigenere.o decrypt.o

test-ascii: test-ascii.o
	g++ -o test-ascii test-ascii.o

main.o: main.cpp
	g++ -c main.cpp

test-ascii.o: test-ascii.cpp
	g++ -c test-ascii.cpp

caesar.o: caesar.cpp caesar.h
	g++ -Wall -c caesar.cpp

vigenere.o: vigenere.cpp vigenere.h
	g++ -Wall -c vigenere.cpp

decrypt.o: decrypt.cpp decrypt.h
	g++ -Wall -c decrypt.cpp

tests.o: tests.cpp doctest.h caesar.h vigenere.h decrypt.h
	g++ -std=c++11 -c tests.cpp

clean:
	rm -f tests main test-ascii *.o
