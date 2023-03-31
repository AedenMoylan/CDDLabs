# defining the object files
OBJS	=  Semaphore.o main.o Barrier.o
# defining the source files
SOURCE	= Semaphore.cpp, main.cpp, Barrier.cpp
# defining the header files
HEADER	= Semaphore.h, Barrier.h
# what the text file used as an executable will be called
OUT	= output
# compiler
CC	 = g++
# specify compiler options
CFLAGS=  -std=c++11 -pthread -g -Wall
DEBUGFLAGS = -DEBUG

# builds all
all: $(OBJS)
	$(CC) $(OBJS) -o $(OUT) $(CFLAGS) $(DEBUGFLAGS)

# deletes object files
clean:
	rm *.o