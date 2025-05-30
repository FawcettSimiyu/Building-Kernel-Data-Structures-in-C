// Circular Queue (FIFO) - Skeleton file
// See a1_header.h for structure and prototype definitions

#include "a1_header.h"
#include <stdio.h>

#define MAX_QUEUE_SIZE 100  // Assumed max size unless specified elsewhere

/**
 * init_queue - Initialize a new circular queue
 * @param queue: Pointer to the CircularQueue structure to initialize
 */
void init_queue(CircularQueue* queue) {
    // TODO: Initialize (front = rear = -1) to indicate empty state. 
    //       Initialize (count = 0) to make numbre of elements zero initially
    queue->front = -1;
    queue->rear = -1;
    queue->count = 0;
}

/**
 * is_queue_empty - Check if the queue is empty
 * @param queue: Pointer to the queue
 * @return: 1 if empty, 0 otherwise
 */
int is_queue_empty(CircularQueue* queue) {
    // TODO: Return 1 if queue is empty    
    return queue->count == 0;
}

/**
 * is_queue_full - Check if the queue is full
 * @param queue: Pointer to the queue
 * @return: 1 if full, 0 otherwise
 */
int is_queue_full(CircularQueue* queue) {
    // TODO: Return 1 if queue is full using circular condition    
    return queue->count == MAX_QUEUE_SIZE;
}

/**
 * enqueue - Add an element to the front of the queue
 * @param queue: Pointer to the queue
 * @param element: Element to add
 * @return: 0 on success, -1 if queue is full
 */
int enqueue(CircularQueue* queue, int element) {
    // TODO: Add an element to the front of the queue
    if (is_queue_full(queue)) {
        return -1;
    }

    if (queue->front == -1) {
        // First element
        queue->front = 0;
        queue->rear = 0;
    } else {
        queue->rear = (queue->rear + 1) % MAX_QUEUE_SIZE;
    }

    queue->data[queue->rear] = element;
    queue->count++;
    return 0;
}

/**
 * dequeue - Remove and return the front element of the queue
 * @param queue: Pointer to the queue
 * @return: front element on success, -1 if queue is empty
 */
int dequeue(CircularQueue* queue) {
    // TODO: Remove and return the front element of the queue    
    if (is_queue_empty(queue)) {
        return -1;
    }

    int value = queue->data[queue->front];

    if (queue->front == queue->rear) {
        // Last element
        queue->front = -1;
        queue->rear = -1;
    } else {
        queue->front = (queue->front + 1) % MAX_QUEUE_SIZE;
    }

    queue->count--;
    return value;
}

/**
 * peek_queue - Return the front element without removing it
 * @param queue: Pointer to the queue
 * @return: Front element if not empty, -1 if queue is empty
 */
int peek_queue(CircularQueue* queue) {
    // TODO: Return the front element without removing it
    if (is_queue_empty(queue)) {
        return -1;
    }

    return queue->data[queue->front];
}

/**
 * queue_size - Return the number of elements in the queue
 * @param queue: Pointer to the queue
 * @return: Number of elements in queue
 */
int queue_size(CircularQueue* queue) {
    // TODO: Calculate queue size accounting for circular wrap-around   
    return queue->count;
}

/**
 * list_queue_size - Prints all elements in the queue from front to rear
 * @param queue: Pointer to the Queue
 * @return: -1 if queue is empty, 0 otherwise after listing elements
 */
int list_queue_elements(CircularQueue* queue) {
   // TODO: List the elements if stack is not empty 
    if (is_queue_empty(queue)) {
        return -1;
    }

    printf("Queue elements from front to rear:");
    for (int i = 0; i < queue->count; i++) {
        printf(" %d", queue->data[(queue->front + i) % MAX_QUEUE_SIZE]);
    }
    printf(" \n");

    return 0;
}


