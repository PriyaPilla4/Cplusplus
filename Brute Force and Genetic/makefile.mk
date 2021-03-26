CFlags= -g -Wall
CC= g++

objects = permutations.cpp bruteforce.cpp genetic.cpp runprogram.cpp main.cpp

main: $(objects)
	$(CC) -o main $(objects)
		
permutations.o: permutations.cpp permutations.hpp 		
bruteforce.o: bruteforce.cpp bruteforce.hpp permutations.hpp		
genetic.o: genetic.cpp genetic.hpp permutations.hpp		
runprogram.o: runprogram.cpp runprogram.hpp permutations.hpp bruteforce.hpp genetic.hpp
main.o: main.cpp permutations.hpp bruteforce.hpp genetic.hpp runprogram.hpp
		
.PHONY : clean
clean:
	rm main $(objects)