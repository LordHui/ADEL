CC = g++
CFLAGS = -Ofast -Wall

LIBS = -lm
SRC = Demo.cpp
OBJ = Demo.o
MAIN = Demo

all:    clean $(MAIN)

$(MAIN): $(OBJ) 
	$(CC) $(CFLAGS) -o $(MAIN) $(OBJ) $(LFLAGS) $(LIBS)

$(OBJ):
	$(CC) $(CFLAGS) -c $(SRC) -o $(OBJ)

clean:
	-rm -f $(OBJ) $(MAIN)

