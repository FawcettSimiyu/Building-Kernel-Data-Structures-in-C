// Circular Linked List - Skeleton file
// See a1_header.h for structure and prototype definitions

#include "a1_header.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * create_node - Allocate and initialize a new node
 * @param data: Value to store in the new node
 * @return: Pointer to the newly created node, EXIT application otherwise
 */
Node* create_node(int data) {
    // TODO: Allocate and initialize node    
    Node* new_node = (Node*)malloc(sizeof(Node));
    if (!new_node) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    new_node->data = data;
    new_node->next = new_node; // Points to itself (circular)
    return new_node;
}

/**
 * is_list_empty - Check if the list is empty
 * @param head: Pointer to head of list
 * @return: 1 if empty, 0 otherwise
 */
int is_list_empty(Node* head) {
    // TODO: Return whether head is NULL    
    return head == NULL;
}

/**
 * insert_node - Insert node into circular list
 * @param head: Current head of list
 * @param new_node: Node to insert
 * @return: New head of the list
 */
Node* insert_node(Node* head, Node* new_node) {
    // TODO: Insert node into circular list    
    if (head == NULL) {
        return new_node;
    }

    Node* temp = head;
    while (temp->next != head) {
        temp = temp->next;
    }

    temp->next = new_node;
    new_node->next = head;
    return head;
}

/**
 * delete_node - Delete a node by key
 * @param head: Head of list
 * @param key: Data value to remove
 * @return: New head of the list if it originally had two or more nodes.
 *          Returns NULL if the list was empty or had only one node (which is deleted).
 */
Node* delete_node(Node* head, int key) {
    // TODO: Remove node with matching data    
    if (head == NULL) {
        return NULL;
    }

    Node *curr = head, *prev = NULL;

    // Single node case
    if (head->next == head && head->data == key) {
        free(head);
        return NULL;
    }

    do {
        if (curr->data == key) {
            if (curr == head) {
                // Find last node to update its next pointer
                Node* last = head;
                while (last->next != head) {
                    last = last->next;
                }
                head = head->next;
                last->next = head;
                free(curr);
                return head;
            } else {
                prev->next = curr->next;
                free(curr);
                return head;
            }
        }
        prev = curr;
        curr = curr->next;
    } while (curr != head);

    return head; // Key not found
}

/**
 * search_node - Search for a node by key
 * @param head: Head of list
 * @param key: Data value to find
 * @return: Pointer to matching node or NULL if key not found or list is empty
 */
Node* search_node(Node* head, int key) {
    // TODO: Search circular list for key    
    if (head == NULL) {
        return NULL;
    }

    Node* curr = head;
    do {
        if (curr->data == key) {
            return curr;
        }
        curr = curr->next;
    } while (curr != head);

    return NULL;
}

/**
 * iterate_list - Traverse and print all nodes
 * @param head: Head of list
 * @return: -1 if list is empty, 0 otherwise
 */
int iterate_list(Node* head) {
    // TODO: Loop through and print each node's data
    if (head == NULL) {
        return -1;
    }

    Node* curr = head;
    do {
        printf("%d ", curr->data);  // print number followed by a space unconditionally
        curr = curr->next;
    } while (curr != head);

    return 0;
}

/**
 * free_list - Frees all nodes in a circular linked list
 * @param head: Head of list
 * @return: -1 if list is already empty, 0 if memory was successfully freed
 */
int free_list(Node* head) {
    // TODO: Traverse the list and free each node
    if (head == NULL) {
        return -1;
    }

    Node* curr = head->next;
    while (curr != head) {
        Node* temp = curr;
        curr = curr->next;
        free(temp);
    }

    free(head);
    return 0;
}

