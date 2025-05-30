// Min-Heap  - Skeleton file
// See a1_header.h for structure and prototype definitions

#include "a1_header.h"
#include <stdio.h>
#include <limits.h>  // For INT_MIN and INT_MAX

#define MAX_HEAP_SIZE 100  // Assumed unless defined elsewhere

void swap_nodes(HeapNode* a, HeapNode* b) {
    HeapNode temp = *a;
    *a = *b;
    *b = temp;
}

/**
 * insert_element - Insert a new element into the min-heap
 * @param heap: Pointer to the MinHeap structure
 * @param element: The HeapNode to insert
 * @return: Simply return if the Heap is full
 */
void insert_element(MinHeap* heap, HeapNode element) {
    /* TODO: Add the element to the end and bubble up to maintain heap property */
    if (heap->size == MAX_HEAP_SIZE) return;

    int i = heap->size;
    heap->data[i] = element;
    heap->size++;

    // Bubble up
    while (i != 0 && heap->data[(i - 1) / 2].priority > heap->data[i].priority) {
        swap_nodes(&heap->data[i], &heap->data[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

/**
 * remove_element - Remove an element at index i from the min-heap
 * @param heap: Pointer to the MinHeap structure
 * @param i: Index of the element to remove
 */
void remove_element(MinHeap* heap, int i) {
    /* TODO: Decrease the priority to INT_MIN, then extract the min */
    decrease_key(heap, i, INT_MIN);
    extract_min(heap);
}

/**
 * extract_min - Extract and return the element with minimum priority
 * @param heap: Pointer to the MinHeap structure
 * @return: HeapNode with the minimum priority
 */
HeapNode extract_min(MinHeap* heap) {
    /* TODO: Check whether Heap empty
             if not, remove the root node and re-heapify */    
    HeapNode dummy = { -1, -1 };

    if (heap->size <= 0) return dummy;

    HeapNode root = heap->data[0];

    heap->data[0] = heap->data[heap->size - 1];
    heap->size--;
    min_heapify(heap, 0);

    return root;
}

/**
 * peek_heap - Return the element with the lowest priority without removing it
 * @param heap: Pointer to the MinHeap structure
 * @return: HeapNode at the top of the heap
 */
HeapNode peek_heap(MinHeap* heap) {
    /* TODO: Check whether Heap empty
             if not, Return the root of the heap */    
    HeapNode dummy = { -1, -1 };

    if (heap->size <= 0) return dummy;

    return heap->data[0];
}

/**
 * decrease_key - Decrease the priority of a node and maintain heap order
 * @param heap: Pointer to the MinHeap structure
 * @param i: Index of the element to update
 * @param new_priority: The new, lower priority value
 */
void decrease_key(MinHeap* heap, int i, int new_priority) {
    /* TODO: Update the priority and bubble up */
    if (new_priority > heap->data[i].priority) return;  // Don't increase priority

    heap->data[i].priority = new_priority;

    while (i != 0 && heap->data[(i - 1) / 2].priority > heap->data[i].priority) {
        swap_nodes(&heap->data[i], &heap->data[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

/**
 * min_heapify - Restore heap property from index i downward
 * @param heap: Pointer to the MinHeap structure
 * @param i: Index from where to start heapifying down
 */
void min_heapify(MinHeap* heap, int i) {
    /* TODO: Compare with children and push down recursively */
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < heap->size && heap->data[left].priority < heap->data[smallest].priority) {
        smallest = left;
    }

    if (right < heap->size && heap->data[right].priority < heap->data[smallest].priority) {
        smallest = right;
    }

    if (smallest != i) {
        swap_nodes(&heap->data[i], &heap->data[smallest]);
        min_heapify(heap, smallest);
    }
}

/**
 * is_heap_empty - Checks if the heap is empty
 * @param heap Pointer to the MinHeap structure
 * @return: 1 if the heap is empty, 0 otherwise
 */
int is_heap_empty(MinHeap* heap) {
   /* TODO: Return whether heap is is zero or not */
   return heap->size == 0;
}

/**
 * Prints all elements in the min heap along with their priorities and indices
 * @param heap Pointer to the MinHeap structure
 * @return: -1 if error, 0 if heap is empty, or the number of elements printed
 */
int list_heap_elements(MinHeap* heap) {    
    // TODO: Loop through all elements and print each one with its index, value and priority    
    if (heap == NULL) return -1;

    if (heap->size == 0) return 0;

    printf("Heap elements (Index[i], Value[v], Priority[p]):");
    for (int i = 0; i < heap->size; i++) {
        printf(" i->[%d] v->%d, p->%d;", i, heap->data[i].value, heap->data[i].priority);
    }
    printf(" \n"); // space before newline to match expected output

    return heap->size;
}
