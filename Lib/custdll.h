typedef struct node_t {
    int data;
    struct node_t *next;
    struct node_t *prev;
} node;

void push (node **head, int data);
void printList (node *head);