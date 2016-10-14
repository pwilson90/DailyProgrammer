make: main

main : main.o
	g++ main.o -o main

main.o: main.cpp
	g++ -c -g -std=c++11 main.cpp

clean:
	rm -r -f *.o main;
