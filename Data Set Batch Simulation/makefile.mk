CFlags= -g -Wall
CC= g++

objects = customer.cpp analytical.cpp simulation.cpp terminal.cpp main.cpp

test: $(objects)
	$(CC) -o test $(objects)
		
customer.o: customer.cpp customer.hpp 		
analytical.o: analytical.cpp analytical.hpp		
simulation.o: simulation.cpp simulation.hpp customer.hpp		
terminal.o: terminal.cpp terminal.hpp simulation.hpp analytical.hpp
main.o: main.cpp terminal.hpp
		
.PHONY : clean
clean:
	rm test $(objects)