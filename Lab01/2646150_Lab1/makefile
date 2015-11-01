lab01: main.o Polynomial.o Executive.o
	g++ -g main.o Polynomial.o Executive.o -o Lab01
main.o: main.cpp Polynomial.o Executive.o
	g++ -g -c main.cpp
Polynomial.o: Polynomial.h Polynomial.cpp
	g++ -g -c Polynomial.cpp -o Polynomial.o
Executive.o: Executive.h Executive.cpp
	g++ -g -c Executive.cpp -o Executive.o
clean:
	rm -f *~ *.o Lab01
