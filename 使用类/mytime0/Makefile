main: usetime0.o mytime0.o
	g++ usetime0.o mytime0.o -o main

usetime0.o: usetime0.cc
	g++ -c usetime0.cc -o usetime0.o

mytime0.o: mytime0.cc
	g++ -c mytime0.cc -o mytime0.o

clean:
	rm -rf *.o main