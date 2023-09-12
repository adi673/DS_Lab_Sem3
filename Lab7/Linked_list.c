#include<stdio.h>

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
    printf("Am here1 \n");
    Node* newNode=createNode(data);
    printf("Am here \n");
    if(head==NULL){
            printf("In head==NULL \n");
        head=newNode;
        tail=newNode;
    }else{
         printf("In else \n");
        Node* temp=head;
        newNode->next=temp;
        head=newNode;
    }
    return;
}

Node* insertAttail(Node* head,Node* tail,int data){
    Node* newNode=createNode(data);
    if(tail==NULL){
        head=newNode;
        tail=newNode;
    }else{
        Node*temp=tail;
        temp->next=newNode;
        tail=newNode;
    }
    return;
}


Node* delete_ele(Node* head, Node* tail, int data){

    if(head==NULL){
        printf("Linked List is empty");
        return;
    }

    if(head->next==NULL){
        int data=head->data;
        free(head);
        printf("Node with value %d is deleted", data);
        return;
    }
    Node* curr=head;
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
    return;

}


void traverse_print(Node* head){
    printf("printing values   ");
    Node* temp=head;
    while(temp!=NULL){
            int data;
        printf("%d ",temp->data);
        if(temp->next==NULL){
            printf("Yes NULL");
        }
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

void sort(){
}

Node* delete_alt(Node* head){
    Node*curr=head;
    Node* next;
    if(curr==NULL){
        return;
    }

    while(curr!=NULL){
        next=curr->next;
        Node* next2=next->next;
        curr->next=next2;
        free(next);
        curr=next2;
        next=next2->next;
    }
    return;
}

Node* insert_inSorted(Node* head, int data){
    Node* newNode=createNode(data);
    if(head==NULL){
        head=newNode;
        return;
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

    Node* head= createNode(5);
    Node* tail=head;
    int n=0;
    while(n!=9){
        printf("1) Insert an element before another element in the existing list\n");
        printf("2) Insert an element after another element in the existing list\n");
        printf("3) Delete a given element from the list\n");
        printf("4) Traverse the list 5) Reverse the list\n");
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
                head=insertAthead(&head,&tail,data1);
                printf("%d ",head->data);
                printf("%d ",head->next->data);
                //traverse_print(head);
                break;
            case 2:
                printf("enter data to insert ");
                int data2;
                scanf("%d", &data2);
                head=insertAttail(head,tail,data2);
                 traverse_print(head);
                break;
            case 3:
                printf("enter data to insert ");
                int data3;
                scanf("%d", &data3);
                head=delete_ele(head,tail,data3);
                 traverse_print(head);
                break;
            case 4:
                traverse_print(head);
                break;
            case 5:
                head=reverseLL(NULL,head);
                traverse_print(head);
                break;
            case 6:
                break;
            case 7:
                delete_alt(head);
                 traverse_print(head);
                break;
            case 8:
                printf("enter data to insert ");
                int data4;
                scanf("%d", &data4);
                head=(head,data4);
                 traverse_print(head);
                break;
        }
    }
}
