#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

// Traverse and print values
void print_list(struct Node* head) {
    while (head != NULL) {
        printf("%d\n", head -> data);
        head = head -> next;
    }
    putchar('\n');
}

// Adds a Node to the beggining of the list
void unshift(struct Node** head_ref, int new_data) {
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
    new_node -> data = new_data;
    new_node -> next = *head_ref;
    *head_ref = new_node;
}

// Adds a Node after a specified Node
void insert_after(struct Node* prev_node, int new_data) {
    if (prev_node == NULL) {
        printf("Previous node cannot be NULL.\n");
        return;
    } 
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
    new_node -> data = new_data;
    new_node -> next = prev_node -> next;
    prev_node -> next = new_node;
}

// Adds a Node to the end of the list
void push(struct Node** head_ref, int new_data) {
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
    new_node -> data = new_data;
    new_node -> next = NULL;
    
    if (*head_ref == NULL) {
        *head_ref = new_node;
    } else {
        struct Node* temp = *head_ref;
        while (temp -> next != NULL) {
            temp = temp -> next;
        }
        temp -> next = new_node;
    }
}

// Deletes the specified node
void delete_node(struct Node** head_ref, struct Node* target_node) {

    if (*head_ref == target_node) {
        if (target_node -> next != NULL) {
            *head_ref = target_node -> next;
        } else {
            *head_ref = NULL;
        }
    } else {
        struct Node* temp = *head_ref;
        while (temp -> next != target_node) {
            temp = temp -> next;
        }
        temp -> next = target_node -> next;
    }
    free(target_node);
}

int main(void) {
    struct Node* head = NULL; // Pointer to the first node of the list

    // Insert values 1 to 5
    for (int i = 1; i < 6; i++) {
        push(&head, i);
    }

    // Insert value 0 in the beginning
    unshift(&head, 0);

    // Insert another value 4
    struct Node* temp = head;
    while ((temp -> data) < 4) {
        temp = temp -> next;
    }
    insert_after(temp, 4);

    // Print resulting list
    print_list(head);

    // Now remove the value 4 added before
    delete_node(&head, temp);

    // Print again
    print_list(head);
    

    return 0;
}