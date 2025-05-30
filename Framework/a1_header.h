/**
 * @file a1_header.h
 * @brief Header file for kernel data structure implementations.
 * Contains structure definitions and function prototypes for stack,
 * circular queue, circular linked list, and min-heap priority queue.
 */

 /* Defining the header guard.*/
#ifndef A1_HEADER_H
#define A1_HEADER_H

/* MAX_SIZE - Maximum number of elements in fixed-size structures.*/
#define MAX_SIZE 100


/* ----------------- STACK ----------------- */
/**
 * Stack - Structure representing a LIFO stack.
 * @data: Array holding stack elements
 * @top: Index of the topmost element
 */
typedef struct {
    int data[MAX_SIZE];
    int top;
} Stack;

void init_stack(Stack* stack);
int is_stack_empty(Stack* stack);
int is_stack_full(Stack* stack);
int push(Stack* stack, int element);
int pop(Stack* stack);
int peek_stack(Stack* stack);
int stack_size(Stack* stack);
int list_stack_elements(Stack* stack);

/* ------------- CIRCULAR QUEUE ------------ */
/**
 * CircularQueue - FIFO queue with circular wrap-around.
 * @data: Storage array
 * @front: Index of front element
 * @rear: Index of rear element
 */
typedef struct {
    int data[MAX_SIZE];
    int front;
    int rear;
    int count;  // Track the exact count of elements
} CircularQueue;

void init_queue(CircularQueue* queue);
int is_queue_empty(CircularQueue* queue);
int is_queue_full(CircularQueue* queue);
int enqueue(CircularQueue* queue, int element);
int dequeue(CircularQueue* queue);
int peek_queue(CircularQueue* queue);
int queue_size(CircularQueue* queue);
int list_queue_elements(CircularQueue* queue);

/* ----------- CIRCULAR LINKED LIST -------- */
/**
 * Node - Single node in circular linked list.
 * @data: Data stored in the node
 * @next: Pointer to the next node in the list
 */
typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* create_node(int data);
int is_list_empty(Node* head);
Node* insert_node(Node* head, Node* new_node);
Node* delete_node(Node* head, int key);
Node* search_node(Node* head, int key);
int iterate_list(Node* head);
int free_list(Node* head);

/* --------------- MIN HEAP ---------------- */
/**
 * HeapNode - Node storing value with associated priority.
 * @value: Payload
 * @priority: Sorting key used by the heap
 */
typedef struct {
    int value;
    int priority;
} HeapNode;

/**
 * MinHeap - Min-heap structure for priority queue.
 * @data: Array of HeapNodes
 * @size: Current number of elements in the heap
 */
typedef struct {
    HeapNode data[MAX_SIZE];
    int size;
} MinHeap;

void insert_element(MinHeap* heap, HeapNode element);
void remove_element(MinHeap* heap, int i);
HeapNode extract_min(MinHeap* heap);
HeapNode peek_heap(MinHeap* heap);
void decrease_key(MinHeap* heap, int i, int new_priority);
void min_heapify(MinHeap* heap, int i);
int is_heap_empty(MinHeap* heap);
int list_heap_elements(MinHeap* heap);

#endif // A1_HEADER_H
