#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* head = NULL;

void insert(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = head;
    head = newNode;
}

void deleteFromStart() {
    if (head == NULL) {
        printf("The list is empty!\n");
    }
    else {
        struct Node* temp = head;
        head = head->next;
        free(temp);
    }
}

void deleteFromEnd() {
    if (head == NULL) {
        printf("The list is empty!\n");
    }
    else if (head->next == NULL) {
        free(head);
        head = NULL;
    }
    else {
        struct Node* current = head;
        while (current->next->next != NULL) {
            current = current->next;
        }
        free(current->next);
        current->next = NULL;
    }
}

void deleteValue(int value) {
    if (head == NULL) {
        printf("The list is empty!\n");
    }
    else if (head->data == value) {
        struct Node* temp = head;
        head = head->next;
        free(temp);
    }
    else {
        struct Node* current = head;
        while (current->next != NULL && current->next->data != value) {
            current = current->next;
        }
        if (current->next == NULL) {
            printf("Value not found!\n");
        }
        else {
            struct Node* temp = current->next;
            current->next = current->next->next;
            free(temp);
        }
    }
}

void deleteBefore(int value) {
    if (head == NULL&&  head->next == NULL && head->data == value) {
        printf("Cannot delete before value!\n");
    }
    else if (head->next->data == value) {
        struct Node* temp = head;
        head = head->next;
        free(temp);
    }
    else {
        struct Node* current = head;
        while (current->next != NULL && current->next->next != NULL && current->next->next->data != value) {
            current = current->next;
        }
        if (current->next == NULL&& current->next->next == NULL) {
            printf("Value not found!\n");
        }
        else {
            struct Node* temp = current->next;
            current->next = current->next->next;
            free(temp);
        }
    }
}

void deleteAfter(int value) {
    if (head == NULL&&  head->next == NULL) {
        printf("Cannot delete after value!\n");
    }
    else {
        struct Node* current = head;
        while (current != NULL && current->data != value) {
            current = current->next;
        }
        if (current == NULL || current->next == NULL) {
            printf("Value not found!\n");
        }
        else {
            struct Node* temp = current->next;
            current->next = current->next->next;
            free(temp);
        }
    }
}

void printList() {
struct Node* current = head;
printf("List: ");
while (current != NULL) {
printf("%d ", current->data);
current = current->next;
}
printf("\n");
}

int main() {
// Insert values
insert(8);
insert(7);
insert(6);
insert(5);
insert(4);
insert(3);
insert(2);
insert(1);
// Print list
printList();

// Delete from start
deleteFromStart();
printList();

// Delete from end
deleteFromEnd();
printList();

// Delete value
deleteValue(5);
printList();

// Delete before
deleteBefore(4);
printList();

// Delete after
deleteAfter(4);
printList();

return 0;
}