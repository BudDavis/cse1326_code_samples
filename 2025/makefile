CXXFLAGS=-Wall -g -std=gnu++17

structured_binding: structured_binding.o
		g++ ${CXXFLAGS} -o structured_binding structured_binding.o

fltk_lambda: fltk_lambda.o
	${CXX} -o fltk_lambda fltk_lambda.o ${CXXFLAGS} -lfltk

clean:
	rm -f structured_binding structured_binding.o
