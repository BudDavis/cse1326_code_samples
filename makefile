CXXFLAGS=-Wall -g -std=gnu++17

structured_binding: structured_binding.o
		g++ ${CXXFLAGS} -o structured_binding structured_binding.o

clean:
	rm -f structured_binding structured_binding.o
