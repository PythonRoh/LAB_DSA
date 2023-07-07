#include <stdio.h>
#define SIZE 10

int hash(int key)
{
    return key % SIZE;
}

void insert(int hashTable[], int key)
{
    int index = hash(key);

    while (hashTable[index] != -1) {
        index = (index + 1) % SIZE;
    }

    hashTable[index] = key;
}

int search(int hashTable[], int key)
{
    int index = hash(key);

    while (hashTable[index] != key) {
        if (hashTable[index] == -1) {
            return -1;
        }

        index = (index + 1) % SIZE;
    }

    return index;
}

void display(int hashTable[])
{
    printf("Hash Table:\n");
    for (int i = 0; i < SIZE; i++) {
        if (hashTable[i] != -1) {
            printf("Index %d: %d\n", i, hashTable[i]);
        }
    }
}

int main()
{
    int hashTable[SIZE];

    // Initialize hash table with -1
    for (int i = 0; i < SIZE; i++) {
        hashTable[i] = -1;
    }

    insert(hashTable, 5);
    insert(hashTable, 15);
    insert(hashTable, 25);
    insert(hashTable, 35);
    insert(hashTable, 45);

    display(hashTable);

    int searchKey = 35;
    int searchIndex = search(hashTable, searchKey);
    if (searchIndex != -1) {
        printf("Element %d found at index %d\n", searchKey, searchIndex);
    } else {
        printf("Element %d not found\n", searchKey);
    }

    return 0;
}