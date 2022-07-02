main: twofile1.o twofile2.o
	g++ twofile1.o twofile2.o -o main

twofile1.o: twofile1.cc
	g++ -c twofile1.cc -o twofile1.o

twofile2.o: twofile2.cc
	g++ -c twofile2.cc -o twofile2.o

clean:
	rm -rf *.o main