main: namesp.o namessp.o
	g++ namesp.o namessp.o -o main

namesp.o: namesp.cc
	g++ -c namesp.cc -o namesp.o

namessp.o: namessp.cc
	g++ -c namessp.cc -o namessp.o

clean:
	rm -rf *.o main