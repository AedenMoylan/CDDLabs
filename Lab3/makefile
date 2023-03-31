OBJS	=  Semaphore.o main.o 
SOURCE	= Semaphore.cpp, main.cpp
HEADER	= Semaphore.h
OUT	= output
CC	 = g++

CFLAGS=  -std=c++11 -pthread -g -Wall
DEBUGFLAGS = -DEBUG

all: $(OBJS)
	$(CC) $(OBJS) -o $(OUT) $(CFLAGS)

clean:
	rm *.o