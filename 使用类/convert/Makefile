main: stonewt.o stone.o
	g++ stone.o stonewt.o -o main

stone.o: stone.cc
	g++ -c stone.cc -o stone.o

stonewt.o: stonewt.cc
	g++ -c stonewt.cc -o stonewt.o

clean:
	rm -rf *.o main