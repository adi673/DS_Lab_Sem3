#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node *next;
}Node;
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}
struct Node* createLinkedList(int arr[], int n, int index) {
    if (index >= n) {
        return NULL;
    }

    struct Node* newNode = createNode(arr[index]);
    newNode->next = createLinkedList(arr, n, index + 1);

    return newNode;
}
void printLinkedList(struct Node* head) {
    if (head == NULL) {
        printf("NULL\n");
        return;
    }

    printf("%d -> ", head->data);
    printLinkedList(head->next);
}

int main(){
    int arr[30],n,index=0;
    printf("enter no of nodes:");
    scanf("%d",&n);
    printf("enter data:");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    struct Node*head= createLinkedList(arr,n,index);
    printLinkedList(head);
    return 0;
}
