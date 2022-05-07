
output: main.o snekNLadder.o
	g++ main.o snekNLadder.o -o output
	
main.o: main.cpp
	g++ -c main.cpp

snekNLadder.o: snekNLadder.cpp snekNLadder.h
	g++ -c snekNLadder.cpp

clean:
	rm *.o output