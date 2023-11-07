#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* llink;
    struct node* rlink;
} node;

node* front = NULL;
node* rear = NULL;

node* create_node(node* prev, int ele, node* next) {
    node* temp = (node*)malloc(sizeof(node));
    temp->rlink = next;
    temp->llink = prev;
    temp->data = ele;
    return temp;
}

node* create_dll(int n, node* first) {
    int i, ele;
    node* last = NULL;
    for (i = 0; i < n; i++) {
        scanf("%d", &ele);
        if (first == NULL) {
            first = last = create_node(NULL, ele, NULL);
            last->rlink = first;
        } else {
            last->rlink = create_node(last, ele, first);
            last = last->rlink;
        }
        first->llink = last;
    }
    rear = last;
    return first;
}

node* delete_node(int srch, node* first, node* rear) {
    node* curr = first;
    node* prev = NULL;

    if (first == NULL) {
        printf("Doubly linked list is empty.\n");
        return NULL;
    }

    do {
        if (curr->data == srch) {
            if (curr == first) {
                first = first->rlink;
                first->llink = rear;
                rear->rlink = first;
                free(curr);
            } else if (curr == rear) {
                prev->rlink = first;
                first->llink = prev;
                rear = prev;
                free(curr);
            } else {
                prev->rlink = curr->rlink;
                curr->rlink->llink = prev;
                free(curr);
            }
            return rear;
        }
        prev = curr;
        curr = curr->rlink;
    } while (curr != first);

    printf("Node not found in the list.\n");
    return rear;
}

void print_dll(node* first) {
    if (first == NULL) {
        printf("Doubly linked list is empty.\n");
        return;
    }

    node* current = first;

    do {
        printf("%d -> ", current->data);
        current = current->rlink;
    } while (current != first);

    printf("...\n");
}

int main() {
    int a, b;
    printf("Enter the number of nodes: ");
    scanf("%d", &a);
    node* first = create_dll(a, front);

    printf("Enter the node to delete: ");
    scanf("%d", &b);
    rear = delete_node(b, first, rear);

    printf("Doubly Linked List: ");
    print_dll(first);

    return 0;
}
