#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

typedef struct Node Node;

// Global head pointer
Node* head = NULL;

// Function to create a new node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the beginning of the list
void insertAtBeginning(int data) {
    Node* newNode = createNode(data);
    
    if (head == NULL) {
        newNode->next = newNode;
    } else {
        Node* temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = head;
    }
    
    head = newNode;
}

// Function to insert a node at the end of the list
void insertAtEnd(int data) {
    Node* newNode = createNode(data);
    
    if (head == NULL) {
        newNode->next = newNode;
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = head;
    }
}

// Function to delete a node at the beginning of the list
void deleteAtBeginning() {
    if (head == NULL) {
        printf("List is empty. Unable to delete.\n");
        return;
    }
    
    Node* temp = head;
    Node* lastNode = head;
    
    while (lastNode->next != head) {
        lastNode = lastNode->next;
    }
    
    if (head->next == head) {
        head = NULL;
    } else {
        head = head->next;
        lastNode->next = head;
    }
    
    free(temp);
}

// Function to delete a node at the end of the list
void deleteAtEnd() {
    if (head == NULL) {
        printf("List is empty. Unable to delete.\n");
        return;
    }
    
    Node* temp = head;
    Node* prevNode = NULL;
    
    while (temp->next != head) {
        prevNode = temp;
        temp = temp->next;
    }
    
    if (prevNode == NULL) {
        head = NULL;
    } else {
        prevNode->next = head;
    }
    
    free(temp);
}

// Function to display the circularly linked list
void displayList() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    
    Node* temp = head;
    //printf("Circular Linked List: ");
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("\n");
}

int main() {
    // Inserting elements into the circular linked list
    insertAtBeginning(4);
    insertAtBeginning(3);
    insertAtBeginning(2);
    insertAtBeginning(1);
    displayList();
    insertAtBeginning(5);
    displayList();
    insertAtEnd(6);
    displayList();
    
    // Displaying the circular linked list
    
    
    // Deleting a node from the beginning of the list
    deleteAtBeginning();
    
    // Displaying the circular linked list after deletion
    displayList();
    
    // Deleting a node from the end of the list
    deleteAtEnd();

    // Displaying the circular linked list after deletion
    displayList();

    return 0;
}