main: brass.o usebrass1.o
	g++ brass.o usebrass1.o -o main

brass.o: brass.cc
	g++ -c brass.cc -o brass.o

usebrass1.o: usebrass1.cc
	g++ -c usebrass1.cc -o usebrass1.o

clean:
	rm -rf *.o main