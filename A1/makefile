SHELL = /bin/sh
CC = gcc
CFLAGS = -O2 -g
LIBNAME = libgraph.a
OBJFILES = graph.o
SHELL_PROFILE = .profile
LIBDIR = /usr/include/newlib
RM = rm -f

install:
	cd ./Q2 && make -f makefile.graph install
	gcc -L/usr/include/newlib -o graph.out main.c -lgraph

clean:
	cd ./Q2 && make -f makefile.graph clean