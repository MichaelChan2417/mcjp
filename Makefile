# this is for Win (mingw32-make ***)
CPP=g++ -Wall -Werror -g -std=c++17

all: mcjp-test example

mcjp-test : mcjp.o mcjp-test.o
	$(CPP) -o '$@' $^

example : example.o mcjp.o
	$(CPP) -o '$@' $^

mcjp.o : mcjp.cpp mcjp.hpp
	$(CPP) -c -o '$@' '$<'

mcjp-test.o : mcjp-test.cpp mcjp.hpp
	$(CPP) -c -o '$@' '$<'

example.o : example.cpp mcjp.hpp
	$(CPP) -c -o '$@' '$<'

clean:
	del /Q *.o mcjp-test.exe example.exe