main: stock1.o usestock1.o
	g++ stock1.o usestock1.o -o main

stock1.o: stock1.cc
	g++ -c stock1.cc -o stock1.o

usestock1.o: usestock1.cc
	g++ -c usestock1.cc -o usestock1.o

clean:
	rm -rf *.o main