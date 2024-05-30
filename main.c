#include "selforg.h"

int main(int argc, char* argv[]) {
    if (argc != 3) {
        printf("Usage: %s <input_file> <output_file>\n", argv[0]);
        return 1;
    }

    FILE* in = openFile(argv[1], "r");
    FILE* out = openFile(argv[2], "w");

    struct Node* head = createNode(0);
    struct Node* found = NULL;
    int num;

    while (fscanf(in, "%d", &num) != EOF) {
        found = searchList(head, num);
        if (found != NULL) {
            if (found->count < MAX_COUNT) {
                found->count++;
                insertAtFront(&head, found);
            }
        } else {
            insertNode(&head, num);
        }
    }

    printList(out, head);
    deleteList(head);

    closeFile(in);
    closeFile(out);

    return 0;
}