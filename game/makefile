CXXFLAGS =-Wall -g -std=gnu++17
CXX=g++

all: checkers move_test 

checkers:checkers.o board.o 


move_test: move_test.o board.o
	${CXX} -o $@ $^ 

clean:
	-rm -f checkers main.o board.o
	-rm -f move_test move_test.o
