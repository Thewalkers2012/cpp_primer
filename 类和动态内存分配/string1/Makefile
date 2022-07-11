main: sayings1.o string1.o
	g++ sayings1.o string1.o -o main

sayings1.o: sayings1.cc
	g++ -c sayings1.cc -o sayings1.o

string1.o: string1.cc
	g++ -c string1.cc -o string1.o

clean:
	rm -rf *.o main