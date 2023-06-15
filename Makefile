
output: main.o PI_algorithm.o
	g++ main.o PI_algorithm.o -o output

main.o: main.cpp
	g++ -c main.cpp

PI_algorithm.o: PI_algorithm.cpp PI_algorithm.h
	g++ -c PI_algorithm.cpp

clean:
	rm *.o output