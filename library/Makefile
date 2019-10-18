#target exe
myexe: fileIO.o library.o
	 g++ $(CFlags) -o myexe fileIO.o library.o

fileIO.o: fileIO.cpp fileIO.h
	g++ $(CFlags) -c fileIO.cpp
	
library.o: library.cpp library.o
	g++ $(CFlags) -c library.cpp

clean:
	rm -f *.o myexe


