
#include<stdio.h>
#include<stdbool.h>


typedef struct Node{
    int data;
    struct Node* next;
    struct Node* prev;
}Node;

Node* createNode(int data){
    printf("creating Node for data %d \n", data);
    Node* newNode=(Node*)malloc(sizeof(Node));
    newNode->data=data;
    newNode->next=NULL;
    newNode->prev=NULL;
    return newNode;
}
//
Node* insertAttail(Node* head,Node* tail,int data){
   Node* newNode=createNode(data);
    //printf("%d", newNode->data);
    Node* temp=head;
    if(temp==NULL){
            printf("in temp is NULL\n");
        head=newNode;
        tail=newNode;
        return tail;
    }
    if(tail==head){
         printf("in tail is head\n");
        newNode->next=NULL;
        newNode->prev=tail;
        tail->next=newNode;
        tail=newNode;
        return tail;
    }
     printf("outside\n");
    newNode->next=NULL;
    newNode->prev=tail;
    tail->next=newNode;
    tail=newNode;
    return tail;
}
//
Node* deleteEleAtTail(Node* head, Node* tail){


    if(head==NULL){
        printf("Linked List is empty");
        return NULL;
    }
    if(head==tail){
        Node* temp=tail;
        free(temp);
        return NULL;
    }
     Node* prev=tail->prev;
     prev->next=NULL;
     Node* temp=tail;
     temp->prev=NULL;
     free(temp);
     tail=prev;

    return tail;
}
//
Node* insertAtPosi(Node* head, Node* tail, int posi,int data){
    Node* newNode=createNode(data);
    Node* temp=head;
    if(head==NULL){
        head=newNode;
        return head;
    }
    if(posi==1){
        newNode->next=head;
        temp->prev=newNode;
        head=newNode;
        return head;
    }

    int count=2;
    while(posi!=count){
        temp=temp->next;
        count++;
    }
    if(temp==tail){
        temp->next=newNode;
        newNode->prev=temp;
        tail=newNode;
        return head;
    }   //left with handling the case of updating tail
    Node* next=temp->next;
    temp->next=newNode;
    newNode->prev=temp;
    newNode->next=next;
    next->prev=newNode;
    return head;
}
//
Node* deleteAtPosi(Node* head, Node* tail, int posi){

    if(head==NULL){
        printf("Linked List is Empty\n");
        return NULL;
    }

    if(posi==1){
        Node* temp=head;
        Node* next=temp->next;
        next->prev=NULL;
        temp->next=NULL;
        free(temp);
        head=next;
        return head;
    }
    Node* temp=head;
    int count=2;
    while(count!=posi){
        temp=temp->next;
        count++;
    }

    if(temp==tail){
        Node*prev=temp->prev;
        prev->next=NULL;
        temp->prev=NULL;
        free(temp);
        tail=prev;
        return head;
    }

    printf("%d ",temp->data);

    Node*prev=temp->prev;

    Node* next=temp->next;

    prev->next=next;
    next->prev=prev;
    temp->prev=NULL;
    temp->next=NULL;
    free(temp);

    return head;
}

Node* insertAfterEle(Node* head, Node* tail, int compiData, int data){
    Node* newNode=createNode(data);

    Node* temp=head;
    int nodeData=temp->data;

    while(compiData!=nodeData){
        temp=temp->next;
        nodeData=temp->data;
    }

    if(tail==temp){
        temp->next=newNode;
        newNode->prev=temp;
        tail=newNode;
        return head;
    }

    Node* next=temp->next;
    temp->next=newNode;
    newNode->prev=temp;
    newNode->next=next;
    next->prev=newNode;
    return head;

}
//
Node* insertBeforele(Node* head, Node* tail, int compiData, int data){
    Node* newNode=createNode(data);

    Node* temp=head;
    int nodeData=temp->data;
    if(compiData==nodeData){
        newNode->next=temp;
        temp->prev=newNode;
        head=newNode;
        return head;
    }

    while(compiData!=nodeData){
        temp=temp->next;
        nodeData=temp->data;
    }

    Node* prev=temp->prev;
    prev->next=newNode;
    newNode->prev=prev;
    newNode->next=temp;
    temp->prev=newNode;
    return head;



}
//
void printLL(Node* head){
    Node* temp=head;

    while(temp!=NULL){

        printf(" %d", temp->data);
        temp=temp->next;
    }

    printf("\n");
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

int main(){

    Node* head= createNode(5);//

    Node* tail=head;
    printLL(head);
    /*
    tail=insertAttail(head,tail,10);
    printLL(head);
    head=insertAtPosi(head, tail, 1,15);
    printLL(head);
    head=insertAtPosi(head, tail, 3,20);
    printLL(head);
    head=reverseLL(NULL,head);
    printLL(head);
    //head=insertBeforele(head,tail,5,7);
    //head=insertBeforele(head,tail,15,7);
    //head=insertBeforele(head,tail,10,7);
    //printLL(head);
printf("enter data to insert at head");
                int data;
                scanf("%d", &data);
                printf("giving command\n");
                Node* head=createNode(data) ;
                Node* tail=head;
                printLL(head);
                printf("\n");*/
    int n;
    scanf("%n",&n);

    while(n!=9){
        printf("1) Insert an element at the rear end of the list\n");
        printf("2) Delete an element from the rear end of the list\n");
        printf("3) Insert an element at a given position of the list\n");
        printf("4) Delete an element from a given position of the list");
        printf("5) Insert an element after another element\n");
        printf("6) Insert an element before another element\n");
        printf("7) Traverse the list\n");
        printf("8) Reverse the list\n");


        scanf("%d", &n);

        switch(n){
            case 1:
                printf("enter data to insert at tail");
                int data1;
                scanf("%d", &data1);
                printf("giving command\n");
                tail=insertAttail(head,tail,data1);
                printLL(head);
                printf("\n");
                break;
            case 2:
                tail=deleteEleAtTail(head,tail);
                printLL(head);
                break;
            case 3:
                printf("enter data to insert\n ");
                int data3;
                scanf("%d", &data3);
                 printf("which positn\n ");
                int posi1;
                scanf("%d", &posi1);
                head=insertAtPosi(head, tail, posi1,data3);
                printLL(head);
                break;
            case 4:
                 printf("which positn to delete\n ");
                 int posi2;
                 scanf("%d", &posi1);
                 head=deleteAtPosi(head, tail,posi2);
                break;
            case 5:
                printf("enter element after which\n ");
                int compiData1;
                scanf("%d", &compiData1);
                 printf("which data to insert\n ");
                int data;
                scanf("%d", data);
                head=insertAfterEle(head,tail,compiData1,data);
                printLL(head);
                break;
            case 6:
                printf("enter element before which\n ");
                int compiData2;
                scanf("%d", &compiData2);
                 printf("which data to insert\n ");
                int data6;
                scanf("%d", data);
                head=insertBeforele(head,tail,compiData2,data6);
                printLL(head);
                break;
            case 7:
                printLL(head);
                break;
            case 8:
                printf("Reversed LL:  ");
                head=reverseLL(NULL,head);
                printLL(head);
                break;
        }
    }

}
