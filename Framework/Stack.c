// Stack implementation (LIFO) - Skeleton file
// See a1_header.h for structure and prototype definitions

#include <stdio.h>          // Added to fix printf implicit declaration
#include "a1_header.h"

#define STACK_CAPACITY 100  // Define capacity if not defined in header

/**
 * init_stack - Initialize a new stack
 * @param stack: Pointer to the stack structure to initialize
 */
void init_stack(Stack* s) {
    // TODO: Initialize the stack by setting top index to indicate empty stack
    s->top = -1;
}

/**
 * is_stack_empty - Check if the stack is empty
 * @param stack: Pointer to the stack
 * @return: 1 if stack is empty, 0 otherwise
 */
int is_stack_empty(Stack* stack) {
    // TODO: Check if the top index indicates empty stack    
    return stack->top == -1;
}

/**
 * is_stack_full - Check if the stack is full
 * @param stack: Pointer to the stack 
 * @return: 1 if stack is full, 0 otherwise
 */
int is_stack_full(Stack* stack) {
    // TODO: Check if the top index reached maximum capacity   
    return stack->top == STACK_CAPACITY - 1;
}

/**
 * push - Push an element onto the stack
 * @param stack: Pointer to the stack 
 * @param element: Element to push onto the stack
 * @return: -1 if stack is full, 0 otherwise
 */
int push(Stack* stack, int element) {
    // TODO: Add element to the top of the stack if not full
    if (is_stack_full(stack)) {
        return -1;
    }
    stack->data[++stack->top] = element;  // Changed from items to data to match struct
    return 0;
}

/**
 * pop - Remove and return the top element from the stack
 * @param stack: Pointer to the stack 
 * @return: Top element if stack is not empty, -1 otherwise
 */
int pop(Stack* stack) {
    // TODO: Remove and return the top element    
    if (is_stack_empty(stack)) {
        return -1;
    }
    return stack->data[stack->top--];      // Changed from items to data
}

/**
 * peek_stack - Return the top element without removing it
 * @param stack: Pointer to the stack 
 * @return: Top element if stack is not empty, -1 otherwise
 */
int peek_stack(Stack* stack) {
    // TODO: Return the top element without popping   
    if (is_stack_empty(stack)) {
        return -1;
    }
    return stack->data[stack->top];        // Changed from items to data
}

/**
 * stack_size - Return the number of elements in the stack
 * @param stack: Pointer to the stack 
 * @return: Number of elements currently in the stack
 */
int stack_size(Stack* stack) {
    // TODO: Calculate size based on top index    
    return stack->top + 1;
}

/**
 * list_stack_size - Prints all elements in the stack from top to bottom
 * @param stack Pointer to the Stack 
 * @return: -1 if stack is empty, 0 otherwise after listing elements
 */
int list_stack_elements(Stack* stack) {
   // TODO: List the elements if stack is not empty 
   if (is_stack_empty(stack)) {
       return -1;
   }

   printf("Stack elements from top to bottom:");
   for (int i = stack->top; i >= 0; i--) {
       printf(" %d", stack->data[i]);
   }
   printf(" \n");

   return 0;
}

