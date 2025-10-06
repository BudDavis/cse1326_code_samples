CXXFLAGS =-Wall -g -std=gnu++17
CXX=g++

all: checkers move_test move_valid

OBJS= board.o move.o 
checkers:checkers.o ${OBJS}


move_test: move_test.o ${OBJS}
	${CXX} -o $@ $^ 

move_valid: move_valid.o move.o 
	${CXX} -o $@ $^ 

clean:
	-rm -f checkers main.o board.o
	-rm -f move_test move_test.o
	-rm -f move_valid  move_valid.o
