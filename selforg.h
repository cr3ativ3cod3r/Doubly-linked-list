#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum exit_nums {EXIT_SAFE, MALLOC_FAIL, IO_FAIL, MAX_COUNT=99};

typedef struct Node {
    int data;
    int count;
    struct Node* next;
} Node;

Node* createNode(int data);
Node* searchList(Node* head, int data);
void insertAtFront(Node** head, Node* node);
void insertNode(Node** head, int data);
void printList(FILE* out, Node* head);
void deleteList(Node* head);
FILE* openFile(char* fileName, char* mode);
void closeFile(FILE* file);
