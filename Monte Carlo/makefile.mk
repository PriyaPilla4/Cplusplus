CFlags= -g -Wall
CC= g++

objects = datasets.cpp monteCarlo.cpp simulation.cpp main.cpp

main: $(objects)
	$(CC) -o main $(objects)
		
datasets.o: datasets.cpp datasets.hpp 		
monteCarlo.o: monteCarlo.cpp monteCarlo.hpp 		
simulation.o: simulation.cpp simulation.hpp datasets.hpp monteCarlo.hpp 
main.o: main.cpp simulation.hpp 
		
.PHONY : clean
clean:
	rm main $(objects)