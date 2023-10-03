#include<stdio.h>
#include<stdbool.h>


typedef struct Node{
    int data;
    struct Node* next;
}Node;

Node* createNode(int data){
    printf("creating Node for data %d \n", data);
    Node* newNode=(Node*)malloc(sizeof(Node));
    newNode->data=data;
    newNode->next=NULL;
    return newNode;
}



Node* insertAthead(Node* head,Node* tail, int data){

    Node* newNode=createNode(data);
    //printf("%d", newNode->data);
    Node* temp=head;
    if(temp==NULL){
            printf("In head==NULL \n");
        head=newNode;
        tail=newNode;
    }else{
        // printf("In else \n");

        newNode->next=temp;
        head=newNode;
    }

    //printf("inserting %d at head\n", data);
    return head;
}

Node* insertAttail(Node* head,Node* tail,int data){
    Node* newNode=createNode(data);
    Node* temp1=head;
    Node* temp2=tail;
    if(temp1==NULL){
        head=newNode;
        tail=newNode;
    }else{

        temp2->next=newNode;
        tail=temp2->next;
    }
    //printf("inserting %d at tail\n", data);
    return tail;
}


Node* delete_ele(Node* head, Node* tail, int data){
    Node* curr=head;

    if(curr==NULL){
        printf("Linked List is empty");
        return NULL;
    }

    if(curr->next==NULL){
        int data=curr->data;
        free(curr);
        printf("Node with value %d is deleted", data);
        return NULL;
    }

    Node* prev=NULL;
    Node* next=curr->next;
    while(curr->data!=data){
        prev=curr;
        curr=next;
        curr=curr->next;
    }

    if(curr->next==NULL){
        prev->next=NULL;
        free(curr);
        tail=prev;
    }
    prev->next=curr->next;
    free(curr);
    return head;

}

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
    return reverseLL(head,next);


}


void sort(Node* head){

    Node* temp=head;
    Node* curr;
    Node* next;
    bool swapped;

    while(temp!=NULL){
        curr=temp->next;
        swapped=false;
        while(curr!=NULL){
            if(temp->data>curr->data){
                int tem=curr->data;
                curr->data=temp->data;
                temp->data=tem;
            }
            curr=curr->next;;
        }
        temp=temp->next;
    }
}



Node* delete_alt(Node* head){
    Node*curr=head;
    Node* next;
    if(curr==NULL){
        return NULL;
    }

    while(curr!=NULL){
        next=curr->next;
        Node* next2=next->next;
        curr->next=next2;

        printf("Freeing %d", next->data);
        free(next);
        printf("\n");
        curr=next2;
        if(next2!=NULL){
            next=next2->next;
        }

    }
    return head;
}


Node* insert_inSorted(Node* head, int data){
    Node* newNode=createNode(data);
    if(head==NULL){
        head=newNode;
        return NULL;
    }
    if(data<head->data){
        newNode->next=head;
        head=newNode;
        return head;
    }
    Node* prev=head;
    Node* curr=head->next;
    int dataLL=curr ->data;
    while(curr!=NULL){

        if(data>prev->data && data<curr->data){
            prev->next=newNode;
            newNode->next=curr;
            return head;
        }
        if(data>prev->data && data==curr->data){
            prev->next=newNode;
            newNode->next=curr;
            return head;
        }

        if(data>=prev->data && data<curr->data){
              prev->next=newNode;
              newNode->next=curr;
              return head;
        }

        prev=curr;
        curr=curr->next;

    }

    if(curr==NULL){
        prev->next=newNode;
        return head;
    }

}



int main(){
/*
    Node* head= NULL;//
    Node* tail=head;
    head=insertAthead(head,tail,20);//
    //printf(" %d tail data 1 main\n ", tail->data);
    tail=insertAttail(head,tail,32);//
    tail=insertAttail(head,tail,35);//
    tail=insertAttail(head,tail,40);//
    head=insertAthead(head,tail,15);//
    head=insertAthead(head,tail,10);//
    head=insertAthead(head,tail,5);//
    printLL(head);
    printf("\n");


    head=reverseLL(NULL,head);

    printLL(head);
    printf("\n");
    //head=delete_alt(head);

    sort(head);
    printLL(head);
*/
  printf("enter data to insert at head");
                int data;
                scanf("%d", &data);
                printf("giving command\n");
                Node* head=createNode(data) ;
                Node* tail=head;
                printLL(head);
                printf("\n");
    int n;
    scanf("%n",&n);

    while(n!=9){
        printf("1) Insert an element before another element in the existing list\n");
        printf("2) Insert an element after another element in the existing list\n");
        printf("3) Delete a given element from the list\n");
        printf("4) Traverse the list");
        printf("5) Reverse the list\n");
        printf("6) Sort the list\n");
        printf("7) Delete every alternate node in the list\n");
        printf("8) Insert an element in a sorted list such that the order is maintained\n");


        scanf("%d", &n);

        switch(n){
            case 1:
                printf("enter data to insert at head");
                int data1;
                scanf("%d", &data1);
                printf("giving command\n");
                head=insertAthead(head,tail,data1);
                printLL(head);
                printf("\n");
                break;
            case 2:
                printf("enter data to insert ");
                int data2;
                scanf("%d", &data2);
                tail=insertAttail(head,tail,data2);
                printLL(head);
                break;
            case 3:
                printf("enter data to insert ");
                int data3;
                scanf("%d", &data3);
                head=delete_ele(head,tail,data3);
                printLL(head);
                break;
            case 4:
                printLL(head);
                break;
            case 5:
                head=reverseLL(NULL,head);
                printLL(head);
                break;
            case 6:
                break;
            case 7:
                delete_alt(head);
                printLL(head);
                break;
            case 8:
                printf("enter data to insert ");
                int data4;
                scanf("%d", &data4);
                head=(head,data4);
                printLL(head);
                break;
        }
    }
}
