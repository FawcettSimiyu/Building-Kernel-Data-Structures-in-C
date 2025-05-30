#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "a1_header.h"

#define LINE_LENGTH 100

 /**************************************************************************        
               DONOT modify this driver code at all
**************************************************************************/

void trim(char *str) {
    char *end;
    while (isspace((unsigned char)*str)) str++;
    if (*str == 0) return;
    end = str + strlen(str) - 1;
    while (end > str && isspace((unsigned char)*end)) end--;
    *(end + 1) = 0;
}

// Convert string to uppercase
void to_uppercase(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = toupper((unsigned char)str[i]);
    }
}

int main() {       
    printf("Stack MAXSIZE: %d\n", MAX_SIZE);
    printf("Circular Queue MAXSIZE: %d\n", MAX_SIZE);
    printf("Circular Queue MAXSIZE: %d\n", MAX_SIZE);
    printf("Min-heap MAXSIZE: %d\n", MAX_SIZE);

    Stack s;
    CircularQueue q;
    Node *list_head = NULL;
     
    MinHeap heap;
    heap.size = 0;

    init_stack(&s);
    init_queue(&q);

    FILE *file = fopen("TESTCASES.txt", "r");
    if (!file) {
        perror("Error opening test_cases.txt");
        return 1;
    }

    char line[LINE_LENGTH];
    char uppercase_line[LINE_LENGTH];
    
    while (fgets(line, sizeof(line), file)) {
        trim(line);
        
        // Skip comments, line with '+' or blank lines
        if (line[0] == '/' || line[0] == '+' ||line[0] == '\0')
            continue;
        
        // Create uppercase version for case comparison
        strcpy(uppercase_line, line);
        to_uppercase(uppercase_line);
        
        /**************************************************************************
                            TESTING Stack Operations
        **************************************************************************/
        if (strncmp(uppercase_line, "PUSH", 4) == 0) {
            int val;
            sscanf(line + 5, "%d", &val);
            if (push(&s, val) == -1)
                printf("Error: Stack Overflow\n");
            else          
                printf("Pushed into stack: %d\n", val);            
        } 
        else if (strncmp(uppercase_line, "POP", 3) == 0) {
            int result = pop(&s);
            if (result == -1)
                printf("Error: Stack Empty\n");
            else
                printf("Popped from stack: %d\n", result);            
        } 
        else if (strncmp(uppercase_line, "PEEK_STACK", 10) == 0) {
            int result = peek_stack(&s);
            if (result == -1)
                printf("Error: Stack Empty\n");
            else
                printf("Top of stack: %d\n", result);
        } 
        else if (strncmp(uppercase_line, "IS_STACK_EMPTY", 14) == 0) {
            printf("Stack empty: %s\n", is_stack_empty(&s) ? "Yes" : "No");
        } 
        else if (strncmp(uppercase_line, "IS_STACK_FULL", 13) == 0) {
            printf("Stack full: %s\n", is_stack_full(&s) ? "Yes" : "No");
        } 
        else if (strncmp(uppercase_line, "STACK_SIZE", 10) == 0) {
            printf("Stack size: %d\n", stack_size(&s));           
        }
        else if (strncmp(uppercase_line, "LIST_STACK_ELEMENTS", 19) == 0) {
            int result = list_stack_elements(&s);
            if (result == -1)
                printf("Error: Stack Empty\n");            
        }  

        /**************************************************************************
                           TESTING Circular Queue Operations
        **************************************************************************/    
        else if (strncmp(uppercase_line, "ENQUEUE", 7) == 0) {
            int val;
            sscanf(line + 8, "%d", &val);
            if (enqueue(&q, val) == -1)
                printf("Error: Queue Full\n");
            else
                printf("Enqueued: %d\n", val);                
        } 
        else if (strncmp(uppercase_line, "DEQUEUE", 7) == 0) {
            int result = dequeue(&q);
            if (result == -1)
                printf("Error: Queue Empty\n");
            else
                printf("Dequeued: %d\n", result);
        } 
        else if (strncmp(uppercase_line, "PEEK_QUEUE", 10) == 0) {
            int result = peek_queue(&q);
            if(result == -1)
                printf("Error: Queue Empty\n");
            else 
                printf("Front of queue: %d\n", result);
        } 
        else if (strncmp(uppercase_line, "IS_QUEUE_EMPTY", 14) == 0) {
            printf("Queue empty: %s\n", is_queue_empty(&q) ? "Yes" : "No");
        } 
        else if (strncmp(uppercase_line, "IS_QUEUE_FULL", 13) == 0) {
            printf("Queue full: %s\n", is_queue_full(&q) ? "Yes" : "No");
        } 
        else if (strncmp(uppercase_line, "QUEUE_SIZE", 10) == 0) {
            printf("Queue size: %d\n", queue_size(&q));        
        }
        else if (strncmp(uppercase_line, "LIST_QUEUE_ELEMENTS", 19) == 0) {
            int result = list_queue_elements(&q);
            if (result == -1)
                printf("Error: Queue Empty\n");                        
        }   

        /**************************************************************************
                        TESTING Circular Linked List operations
        **************************************************************************/
        else if (strncmp(uppercase_line, "INSERT_NODE", 11) == 0) {
            int val;
            sscanf(line + 12, "%d", &val);
            Node *node = create_node(val);
            list_head = insert_node(list_head, node);
            printf("Node inserted is: %d\n", val);
        } 
        else if (strncmp(uppercase_line, "DELETE_NODE", 11) == 0) {
            int key;
            sscanf(line + 12, "%d", &key);
            list_head = delete_node(list_head, key);
            printf("Node deleted is: %d\n", key);
        } 
        else if (strncmp(uppercase_line, "SEARCH_NODE", 11) == 0) {
            int key;
            sscanf(line + 12, "%d", &key);
            Node *found = search_node(list_head, key);
            printf("Node %d %s\n", key, found ? "found" : "not found");
        } 
        else if (strncmp(uppercase_line, "ITERATE_LIST", 12) == 0) {
            if (is_list_empty(list_head)) {
                printf("List is empty\n");
            } else {
                printf("List nodes are: ");
                iterate_list(list_head);
                printf("\n");
            }
        }
        else if (strncmp(uppercase_line, "IS_LIST_EMPTY", 13) == 0) {
            printf("List empty: %s\n", is_list_empty(list_head) ? "Yes" : "No");
        }
        else if (strncmp(uppercase_line, "FREE_LIST", 9) == 0) {
            if (free_list(list_head) == -1)
                printf("List is already empty\n");
            else    
                printf("List has been emptied\n");
            list_head = NULL;  // Reset list_head after freeing
        } 
        
        /**************************************************************************
                               TESTING Min-heap operations
        **************************************************************************/
        else if (strncmp(uppercase_line, "INSERT_ELEMENT", 14) == 0) {
            int val, priority;
            sscanf(line + 15, "%d %d", &val, &priority);
            HeapNode node = {val, priority};
            insert_element(&heap, node);
            printf("Inserted element: value=%d, priority=%d\n", val, priority);
        } 
        else if (strncmp(uppercase_line, "EXTRACT_MIN", 11) == 0) {
            if (heap.size == 0) {
                printf("Error: Heap Empty\n");
            } else {
                HeapNode min = extract_min(&heap);
                printf("Extracted min: value=%d, priority=%d\n", min.value, min.priority);
            }
        } 
        else if (strncmp(uppercase_line, "PEEK_HEAP", 9) == 0) {
            if (heap.size == 0) {
                printf("Error: Heap Empty\n");
            } else {
                HeapNode min = peek_heap(&heap);
                printf("Top of heap: value=%d, priority=%d\n", min.value, min.priority);
            }
        } 
        else if (strncmp(uppercase_line, "DECREASE_KEY", 12) == 0) {
            int index, new_priority;
            sscanf(line + 13, "%d %d", &index, &new_priority);
            decrease_key(&heap, index, new_priority);
            printf("Decreased priority of element at index %d to %d\n", index, new_priority);
        } 
        else if (strncmp(uppercase_line, "REMOVE_ELEMENT", 14) == 0) {
            int index;
            sscanf(line + 15, "%d", &index);
            remove_element(&heap, index);
            printf("Removed element at index %d\n", index);
        }
        else if (strncmp(uppercase_line, "IS_HEAP_EMPTY", 13) == 0) {
             printf("Heap empty: %s\n", is_heap_empty(&heap) ? "Yes" : "No");
        } 
        else if (strncmp(uppercase_line, "LIST_HEAP_ELEMENTS", 18) == 0) {
            int result = list_heap_elements(&heap);
            if (result == 0)
                printf("Error: Heap Empty\n");                        
        }   
        else {
            printf("Unknown command: %s\n", line);
        }
    }

    fclose(file);    
    return 0;
}