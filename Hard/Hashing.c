#include <stdio.h>
#include <stdlib.h>
#define size 7

typedef struct Node {
    int key;
    int data;
}node;

typedef struct hashTable {
    node* array[size];
}hash;

void createHash(hash* ht) {
    for (int i = 0; i < size; i++) {
        ht->array[i] = NULL;
    }
}

void insert(hash* ht, int key, int data) {
    node* p = (node*)malloc(sizeof(node));
    p->key = key;
    p->data = data;
    int index = key % size;
    //Linear probing
    while (ht->array[index] != NULL) {
        index = (index + 1) % size;
    }
    ht->array[index] = p;
}

void printHash(hash* ht) {
    printf("Hash Table:\n");
    for (int i = 0; i < size; i++) {
        if (ht->array[i] != NULL) {
            printf("Index %d: Key=%d, Data=%d\n", i, ht->array[i]->key, ht->array[i]->data);
        } else {
            printf("Index %d: Empty\n", i);
        }
    }
}

int main() {
    struct hashTable hashTable;
    createHash(&hashTable);
    insert(&hashTable, 5, 50);
    insert(&hashTable, 25, 250);
    insert(&hashTable, 15, 150);
    insert(&hashTable, 35, 350);
    printHash(&hashTable);
    return 0;
}
