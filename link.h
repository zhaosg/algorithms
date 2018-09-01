typedef struct {
    int value;
    struct Node *next;
} Node;

void node_insert(Node *a, Node *b) {
    b->next = a->next;
    a->next = b;
}

void node_print(Node *head) {
    Node *current = head;
    do {
        printf("%d", current->value);
        current = current->next;
        if (current != NULL) {
            printf("->");
        }
    } while (current != NULL);
}

void node_delete(Node *head, Node *x) {
    Node *current = head;
    char found = 0;
    while (!found) {
        if (current->next == x) {
            current->next = x->next;
            found = 1;
        } else {
            current = current->next;
        }
    }
}