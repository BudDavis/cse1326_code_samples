
CPPFLAGS+= -Wall -std=gnu++17 -g -O0
CXX=g++

radioButtons:radioButtons.cpp main.cpp
	${CXX} $^ ${CPPFLAGS} `pkg-config gtkmm-4.0 --cflags --libs` -o $@

clean:
	-rm -f radioButtons
