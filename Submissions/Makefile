CC = gcc
CFLAGS = -Wall -Wextra -pedantic -std=c99

OBJ = driver.o Stack.o Circular_Queue.o Circular_Linked_List.o Min_Heap.o
TARGET = datastructure

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJ)

driver.o: driver.c a1_header.h
	$(CC) $(CFLAGS) -c driver.c

Stack.o: Stack.c a1_header.h
	$(CC) $(CFLAGS) -c Stack.c

Circular_Queue.o: Circular_Queue.c a1_header.h
	$(CC) $(CFLAGS) -c Circular_Queue.c

Circular_Linked_List.o: Circular_Linked_List.c a1_header.h
	$(CC) $(CFLAGS) -c Circular_Linked_List.c

Min_Heap.o: Min_Heap.c a1_header.h
	$(CC) $(CFLAGS) -c Min_Heap.c

clean:
	rm -f $(OBJ) $(TARGET)

