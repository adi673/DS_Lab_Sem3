#include<stdio.h>
#include<stdlib.h>
typedef struct Node {
 int data;
 struct Node* next;
 struct Node* prev;
} Node;
// Function prototypes
Node* createNode(int data);
void insert(Node* header, int data);
void display(Node* header);
void delete_rear(Node* first);
void insert_at(Node *first,int pos,int d);
void delete_at_pos(Node* head,int pos);
void insert_after_ele(Node* head,int data,int d);
void insert_before_ele(Node* head,int y,int d);
Node* reverseLL(Node*prev,Node* head);
int main() {
 Node* header = createNode(-1); // Header node with data -1
 int choice, data;
 while (1) {
 printf("\n1. Insert an element\n");
 printf("2. Display the doubly linked list\n");
 printf("3. Exit\n");
 printf("4. delete rear\n");
 printf("5. insert at pos\n");
  printf("6. delete at pos\n");
printf("7. insert after element\n");
printf("8. insert before element\n");
printf("9. reversing list\n");
 printf("Enter your choice: ");
 scanf("%d", &choice);
 switch (choice) {
 case 1:
 printf("Enter the element to insert: ");
 scanf("%d", &data);
 insert(header, data);
 break;
 case 2:
 display(header);
 break;
 case 3:
 printf("Exiting the program.\n");
 return 0;
 case 4:
    printf("deleteing....");
    delete_rear(header);
    break;
 case 5:
    printf("Enter the element to insert: ");
    scanf("%d", &data);
    printf("Enter the pos to insert: ");
    int pos;
    scanf("%d", &pos);
    insert_at(header,pos,data);
    break;
 case 6:
    printf("enter pos to delete starting from pos 0\n");
    scanf("%d",&data);
    delete_at_pos(header,data);
    break;
 case 7:
    printf("Enter the element to insert: ");
    scanf("%d", &data);
    printf("Enter the data after you want it to go: ");
    int x;
    scanf("%d", &x);
    insert_after_ele(header,data,x);
    break;
 case 8:
    printf("Enter the element to insert: ");
    scanf("%d", &data);
    printf("Enter the data before you want it to go: ");
    int y;
    scanf("%d", &y);
    insert_before_ele(header,data,y);
    break;
 case 9:
    header=reverseLL(NULL, header);
    break;
 default:
 printf("Invalid choice! Please try again.\n");
 break;
 }
 }
 return 0;
}
// Function to create a new node
Node* createNode(int data) {
 Node* newNode = (Node*)malloc(sizeof(Node));
 newNode->data = data;
 newNode->next = NULL;

 newNode->prev = NULL;
 return newNode;
}
// Function to insert a new element at the end of the doubly linked list
void insert(Node* header, int data) {
 Node* newNode = createNode(data);
 Node* current = header;
 while (current->next != NULL) {
 current = current->next;
 }
 current->next = newNode;
 newNode->prev = current;
}
// Function to display the elements of the doubly linked list
void display(Node* header) {
 if (header->next == NULL) {
 printf("Doubly linked list is empty.\n");
 return;
 }
 Node* current = header->next;
 printf("Doubly linked list elements: ");
 while (current != NULL) {
 printf("%d ", current->data);
 current = current->next;
 }
 printf("\n");
}
void delete_rear(Node* first){
    if(first==NULL)
        printf("list is empty\n");
    else if(first->next==NULL){
        free(first);
        first=NULL;
    }
    else{
        Node *temp=first,*temp2=first;
        while(temp->next!=NULL){
            temp2=temp;
            temp=temp->next;
        }
        temp2->next=NULL;
        free(temp);
        temp=NULL;
    }

}
void insert_at(Node *first,int pos,int d){
    int count=1,length=1;
    Node* newNode = createNode(d);
    printf("first:%d",first->data);
    Node *curr=first->next;
    Node*tail=curr;
    while(tail->next!=NULL){
        length++;
        tail=tail->next;
    }
    if(pos==1){
        first->next=newNode;
        curr->prev=newNode;
        newNode->next=curr;
        newNode->prev=first;
        curr=newNode;
        display(first);

    }
    else if(pos==length+1){
        tail->next=newNode;
        newNode->prev=tail;
    }
    else{

    while(count!=pos-1&&curr->next!=NULL){
       curr=curr->next;
       count++;
    }
    Node *temp=curr->next;
    temp->prev=newNode;
    newNode->next=temp;
    curr->next=newNode;
    newNode->prev=curr;
}
}
void delete_at_pos(Node* head,int pos){
    int count=1;
    Node *curr=head->next;
    if(pos==1){
        head=curr;
        display(head);
    }
    else{
        Node *last=NULL;
        while(count!=pos-1){
            last=curr;
            curr=curr->next;
            count++;
        }
        Node *temp=curr->next;
        last->next=temp;
        temp->prev=last;
        free(curr);
    }
}
void insert_after_ele(Node* head,int y,int d){
    Node *curr=head;
    while(curr->data!=d && curr->next!=NULL){
        curr=curr->next;
    }
    if(curr->data==d){
    Node* newNode = createNode(y);
    Node *temp=curr->next;
    temp->prev=newNode;
    newNode->next=temp;
    curr->next=newNode;
    newNode->prev=curr;
    }
}
void insert_before_ele(Node* head,int y,int d){
    Node *curr=head,*before;
    while(curr->data!=d || curr->next!=NULL){
        curr=curr->next;
    }
    if(curr->data==d){
    Node* newNode = createNode(y);
    before=curr->prev;
    before->next=newNode;
    newNode->next=curr;
    curr->prev=newNode;
    newNode->prev=before;
    }
}
Node* reverseLL(Node*prev,Node* head){

    if(head==NULL){
        return prev;
    }

    Node* next=head->next;
    head->next=prev;
    head->prev=next;
    return reverseLL(head,next);


}
