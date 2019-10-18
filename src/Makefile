#target exe
myexe: utilities.o Project2.o array_functions.o
	 g++ $(CFlags) -o myexe utilities.o Project2.o array_functions.o

utilities.o: utilities.cpp utilities.h
	g++ $(CFlags) -c utilities.cpp
	
Project2.o: Project2.cpp
	g++ $(CFlags) -c Project2.cpp

array_functions.o: array_functions.cpp array_functions.h
	g++ $(CFlags) -c array_functions.cpp

clean:
	rm -f *.o myexe


