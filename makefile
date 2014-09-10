
# Define the compiler
CC=g++
# Define the compiler options
CFLAGS=-O2
# Define the linker
LINK=g++

all: EvaulPostfix

# Define the dependencies
EvaulPostfix: EvaulPostfix.o
	$(LINK) -o EvaulPostfix EvaulPostfix.o
	
EvaulPostfix.o: EvaulPostfix.cpp List.h
	$(CC) -c $(CFLAGS) -std=c++0x EvaulPostfix.cpp 
###
clean:
	/bin/rm -f EvaulPostfix EvaulPostfix.o	
 