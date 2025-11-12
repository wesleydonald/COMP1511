// main.c
// Written by Wesley Donald
// Program to test linked lists functions

#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

// Creates a new node
//
// Parameters:
//      data: The data to be stored in the new node
//
// Returns:
//      A pointer to the new node
struct node *create_node(int data);

// Inserts a new node at the head of a linked list
//
// Parameters:
//      head: A pointer to the head of the linked list
//      data: The data to be stored in the new node
//
// Returns:
//      A pointer to the new head of the linked list
struct node *insert_head(struct node *head, int data);

// Inserts a new node at the tail of a linked list
//
// Parameters:
//      head: A pointer to the head of the linked list
//      data: The data to be stored in the new node
//
// Returns:
//      A pointer to the head of the linked list
struct node *insert_tail(struct node *head, int data);

// Traverses a linked list and prints the data in each node
//
// Parameters:
//      head: A pointer to the head of the linked list
//
// Returns:
//      None
void print_list(struct node *head);

// Finds the number of nodes in a linked list
//
// Parameters:
//      head: A pointer to the head of the linked list
//
// Returns:
//      The number of nodes in the linked list
int list_length(struct node *head);

// Removes the tail of a linked list
//
// Parameters:
//      head: A pointer to the head of the linked list
//
// Returns:
//      A pointer to the head of the linked list
struct node *remove_tail(struct node *head);
void free_list(struct node *head);
int list_count_occurrences(struct node *head, int data);
struct node *list_delete_smallest(struct node *head);
struct node *list_append(struct node *head1, struct node *head2);
struct node *list_reverse(struct node *head);

int main(void) {

    // Create a pointer to the head of the linked list
    struct node *head = NULL;

    // Insert a node at the beginning of the linked list
    head = insert_head(head, 10);

    // Insert a node at the beginning of the linked list
    head = insert_head(head, 5);

    // Insert a node at the end of the linked list
    head = insert_tail(head, 15);

    // Insert a node at the end of the linked list
    head = insert_tail(head, 20);

    // Print the linked list
    print_list(head);

    // Calculate and print the length of the linked list
    int length = list_length(head);
    printf("There are %d nodes in the list\n", length);
    
    // Remove the last node from the linked list
    head = list_reverse(head);

    // Print the linked list
    print_list(head);

    // Calculate and print the length of the linked list
    length = list_length(head);
    printf("There are %d nodes in the list\n", length);
    free_list(head);
    return 0;
}


struct node *create_node(int data) {
    struct node *new_node = malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = NULL;

    return new_node;
}

struct node *insert_head(struct node *head, int data) {
    // Create a new node
    struct node *new_node = create_node(data);
    new_node->next = head;

    return new_node;
}

struct node *insert_tail(struct node *head, int data) {
    // Create a new node
    struct node *new_node = create_node(data);

    // If the linked list is empty, return the new node
    if (head == NULL) {
        return new_node;
    }

    // Traverse the linked list to find the last node
    struct node *current = head;
    while (current->next != NULL) {
        current = current->next;
    }

    // Insert the new node at the end of the linked list
    current->next = new_node;

    return head;
}

void print_list(struct node *head) {
    // Set current to be the first node in the list
    struct node *current = head;
    
    // Traverse the linked list and print each node 
    // until we reach the end of the list
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("X\n");
}

int list_length(struct node *head) {
    // Initialize the length of the list to 0
    int length = 0;

    // Set current to be the first node in the list
    struct node *current = head;

    // Traverse the linked list and increment the length
    // until we reach the end of the list
    while (current != NULL) {
        length++;
        current = current->next;
    }

    return length;
}

void free_list(struct node *head) {
    struct node *current = head;
    while (current != NULL) {
        // free current
        // look at the next node
        struct node *temp = current->next;
        free(current);
        current = temp;
    }
    return;
}

struct node *remove_head(struct node *head) {
    struct node *temp = head;
    head = head->next;
    free(temp);
    return head;
}

struct node *remove_tail(struct node *head) {
    if (head == NULL) {
        return NULL;
    }

    if (head->next == NULL) {
        free(head);
        return NULL;
    }

    struct node *current = head;
    while (current->next->next != NULL) {
        current = current->next;
    }
    struct node *temp = current->next;
    current->next = NULL;
    free(temp);

    return head;
}

int list_count_occurrences(struct node *head, int data) {
    struct node *current = head;
    int counter = 0;
    while (current != NULL) {
        if (current->data == data) {
            counter += 1;
        }
        current = current->next;
    }
    return counter;
}

struct node *list_delete_smallest(struct node *head) {
    struct node *current = head;
    // special case for empty list
    // special case for list of length one
    int min_value = head->data;
    while (current != NULL) {
        if (current->data < min_value) {
            min_value = current->data;
        }
        current = current->next;
    }

    // special case to delete the head
    current = head;
    while (current->next->data != min_value) {
        current = current->next;
    }

    struct node *temp = current->next;
    current->next = current->next->next;
    free(temp);

    return head;
}

struct node *list_reverse(struct node *head) {
    struct node *current = head;
    head = NULL;
    while (current != NULL) {
        struct node *temp = current->next;
        current->next = head;
        head = current;
        current = temp;
    }
    return head;
}

struct node *list_append(struct node *head1, struct node *head2) {
    if (head1 == NULL) {
        return head2;
    }
    struct node *current = head1;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = head2;
    return head1;
}
