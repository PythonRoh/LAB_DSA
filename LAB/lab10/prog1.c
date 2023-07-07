#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

struct node {
    int data;
    struct node* next;
};

struct node* hashTable[SIZE] = {NULL};

int hashFunction(int key) {
    return key % SIZE;
}

void insert(int key) {
    int index = hashFunction(key);

    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = key;
    newNode->next = NULL;

    if (hashTable[index] == NULL) {
        hashTable[index] = newNode;
    } else {
        struct node* current = hashTable[index];
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
}

void display() {
    int i;
    for (i = 0; i < SIZE; i++) {
        printf("Index %d: ", i);
        struct node* current = hashTable[i];
        while (current != NULL) {
            printf("%d -> ", current->data);
            current = current->next;
        }
        printf("NULL\n");
    }
}

int main() {
    insert(1);
    insert(2);
    insert(3);
    insert(4);
    insert(5);
    insert(15);
    insert(25);
    insert(35);
    insert(45);
    insert(55);

    display();

    return 0;
}