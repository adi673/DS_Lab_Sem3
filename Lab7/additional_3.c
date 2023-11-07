#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node * next;
}node;

node * create(int n)
{
    node * first = NULL;
    node * curr = NULL;
    if(n == 0)
    {
        return first;
    }

    else
    {
        node * temp = (node *) malloc(sizeof(node));
        printf("Enter data: ");
        scanf("%d", &temp -> data);
        temp -> next = NULL;

        if(first == NULL)
        {
            first = curr = temp;
        }

        else
        {
            curr -> next = temp;
            curr = temp;
        }
    }

    first -> next = create(n - 1);

    return first;
}

void disp(node * first)
{
    node * curr;
    if(first == NULL)
    {
        printf("List is empty\n");
    }

    else
    {
        for(curr = first; curr != NULL; curr = curr -> next)
        {
            printf("%d\t", curr -> data);
        }
        printf("\n");
    }
}
node* createNode(int data){
    node*newnode=(node*)malloc(sizeof(node));
    newnode->next=NULL;
    return newnode;
}

node * merge(int n, int m, node * head1, node * head2){
    node*changehead=(node *) malloc(sizeof(node));
    changehead->data=-1;
    changehead->next=NULL;
   node*mainhead=changehead;
    while((head1!=NULL)&&(head2!=NULL)){
        int datax,datay;
        datax=head1->data;
        datay=head2->data;
        node*newNode1;
        newNode1=(node *) malloc(sizeof(node));
        newNode1->data=datax;
        newNode1->next=NULL;
        node*newNode2;
        newNode2=(node *) malloc(sizeof(node));
        newNode2->data=datay;
        newNode2->next=NULL;
        changehead->next=newNode1;
        newNode1->next=newNode2;
        changehead=newNode2;
        head1=head1->next;
        head2=head2->next;
    }
    if(head1==NULL){
        changehead->next=head2;
            return mainhead->next;
    }
    if(head2==NULL){
        changehead->next=head1;
        return mainhead->next;
    }

}

int main(void)
{
    node * a = NULL;
    node * b = NULL;
    node * c = NULL;

    int p, q;
    printf("Enter number of nodes in list x: ");
    scanf("%d", &p);
    printf("Enter data for x: \n");
    a = create(p);
    disp(a);
    printf("\n");

    printf("Enter number of nodes in list y: ");
    scanf("%d", &q);
    printf("Enter data for y: \n");
    b = create(q);
    disp(b);
    printf("\n");

    c = merge(p, q, a, b);
    printf("New List is : \n");
    disp(c);
}
