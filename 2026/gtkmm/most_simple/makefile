
CPPFLAGS+= -Wall -std=gnu++17 -g 
CXX=g++

minimal_gtk:minimal_gtk.cpp
	${CXX} $< ${CPPFLAGS} `pkg-config gtkmm-4.0 --cflags --libs` -o minimal_gtk
