#include "selforg.h"

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->count = 1;
    newNode->next = NULL;
    return newNode;
}

struct Node* searchList(struct Node* head, int data) {
    struct Node* current = head->next;
    while (current != NULL) {
        if (current->data == data) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

void insertAtFront(struct Node** head, struct Node* node) {
    struct Node* prev = *head;
    struct Node* curr = (*head)->next;
    
    while (curr != NULL && curr != node) {
        prev = curr;
        curr = curr->next;
    }

    if (curr == node) {
        prev->next = curr->next;
        curr->next = (*head)->next;
        (*head)->next = curr;
    }
}

void insertNode(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    newNode->next = (*head)->next;
    (*head)->next = newNode;
}

void printList(FILE* out, struct Node* head) {
    struct Node* current = head->next;
    while (current != NULL) {
        fprintf(out, "%d %d\n", current->data, current->count);
        current = current->next;
    }
}

void deleteList(struct Node* head) {
    struct Node* current = head;
    struct Node* next;

    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
}