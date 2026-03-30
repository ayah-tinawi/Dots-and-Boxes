CC = gcc
CFLAGS = -Wall -Wextra -std=c11 -g
TARGET = dots

all: $(TARGET)

$(TARGET): main.o game.o
	$(CC) $(CFLAGS) -o $(TARGET) main.o game.o

main.o: main.c game.h
	$(CC) $(CFLAGS) -c main.c

game.o: game.c game.h
	$(CC) $(CFLAGS) -c game.c

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f *.o $(TARGET)