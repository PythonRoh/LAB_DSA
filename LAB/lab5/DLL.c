#include <stdio.h>
#include <stdlib.h>

// Define the node structure for the linked list
struct node {
    int data;
    struct node* next;
};

// Create a new node with the given data
struct node* createNode(int data) {
    struct node* newNode = (struct node*) malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Insert a new node at the beginning of the list
void insertAtStart(struct node** head, int data) {
    struct node* newNode = createNode(data);
    newNode->next = *head;
    *head = newNode;
}

// Insert a new node at the end of the list
void insertAtEnd(struct node** head, int data) {
    struct node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct node* current = *head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newNode;
}

// Insert a new node between two existing nodes
void insertBetween(struct node** head, int newData, int afterData, int beforeData) {
    struct node* newNode = createNode(newData);
    struct node* current = *head;
    while (current != NULL && current->data != beforeData) {
        if (current->data == afterData) {
            newNode->next = current->next;
            current->next = newNode;
        }
        current = current->next;
    }
}

// Insert a new node before a specified node
void insertBefore(struct node** head, int newData, int beforeData) {
    struct node* newNode = createNode(newData);
    struct node* current = *head;
    if (current->data == beforeData) {
        newNode->next = current;
        *head = newNode;
        return;
    }
    while (current->next != NULL && current->next->data != beforeData) {
        current = current->next;
    }
    newNode->next = current->next;
    current->next = newNode;
}

// Insert a new node after a specified node
void insertAfter(struct node** head, int newData, int afterData) {
    struct node* newNode = createNode(newData);
    struct node* current = *head;
    while (current != NULL && current->data != afterData) {
        current = current->next;
    }
    newNode->next = current->next;
    current->next = newNode;
}

// Print the contents of the linked list
void printList(struct node* head) {
    struct node* current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    // Create the list with 1, 2, and 3
    struct node* head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(3);
printList(head);
    // Insert 4 at the start
    insertAtStart(&head, 4);
    printList(head);

    // Insert 5 at the end
    insertAtEnd(&head, 5);
printList(head);
    // Insert 6 between
insertBetween(&head, 6, 2, 3);
printList(head);
// Insert 7 before 1
insertBefore(&head, 7, 1);
printList(head);
// Insert 8 after 3
insertAfter(&head, 8, 3);
printList(head);
// Print the contents of the list


return 0;
}