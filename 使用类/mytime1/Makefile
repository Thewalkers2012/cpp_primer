main: usetime1.o mytime1.o
	g++ usetime1.o mytime1.o -o main

usetime1.o: usetime1.cc
	g++ -c usetime1.cc -o usetime1.o

mytime1.o: mytime1.cc
	g++ -c mytime1.cc -o mytime1.o

clean:
	rm -rf *.o main