main: stringbad.o vegnews.o
	g++ stringbad.o vegnews.o -o main

stringbad.o: stringbad.cc
	g++ -c stringbad.cc -o stringbad.o

vegnews.o: vegnews.cc
	g++ -c vegnews.cc -o vegnews.o

clean:
	rm -rf *.o main