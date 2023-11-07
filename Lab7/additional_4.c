#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int data;
    struct node *next;
} node;

node *head1 = NULL;
node *head2 = NULL;
node *tail=NULL;

void insert1()
{
   node *ptr;
    ptr=(node*)malloc(sizeof(node));
    if(ptr==NULL)
    {
        printf("overflow");
    }

    else
    {
        printf("enter the number\n");
        scanf("%d",&ptr->data);

        if(head1==NULL)
        {
            ptr->next=NULL;
            head1=ptr;
        }

        else
        {
            node*curr=ptr;
            curr->next=head1;
            head1=curr;
        }
    }
}

void insert2()
{
    node *ptr;

    ptr=(node*)malloc(sizeof(node));
    if(ptr==NULL)
    {
        printf("overflow");
    }

    else
    {
        printf("enter the number\n");
        scanf("%d",&ptr->data);

        if(head2==NULL)
        {
            ptr->next=NULL;
            head2=ptr;
            tail=head2;
        }

        else
        {
            ptr->next=NULL;
            tail->next=ptr;
            tail=ptr;

        }
    }
}

void delete1()
{
  if(head1==NULL)
    {
        printf("the stack is empty\n");
    }

    else
    {
       node*curr=head1;
       head1=head1->next;
        curr->next=NULL;
        free(curr);
    }
}

void delete2()
{
    if(head2==NULL)
    {
        printf("the queue is empty");
    }

    else
    {
        node*curr=head2;
        head2=head2->next;
        curr->next=NULL;
        free(curr);
    }
}

void show(node *head)
{
   node *temp=head;
    while(temp!=NULL)
    {
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("\n");
}

int main()
{
    int c1, c2, c3;

    printf("Choose one option:\n");
    printf("1. STACK\n2. QUEUE\n");
    scanf("%d", &c1);

    switch (c1)
    {
        case 1:
            while (1)
            {
                printf("1. Choose to enter the element\n");
                printf("2. Choose to delete the element\n");
                printf("3. Choose to display the stack\n");
                printf("4. Exit\n");
                scanf("%d", &c2);
                switch (c2)
                {
                    case 1:
                        insert1();
                        break;

                    case 2:
                        delete1();
                        break;

                    case 3:
                        show(head1);
                        break;

                    case 4:
                        return 0;
                }
            }

        case 2:
            while (1)
            {
                printf("1. Choose to enter the element\n");
                printf("2. Choose to delete the element\n");
                printf("3. Choose to display the queue\n");
                printf("4. Exit\n");
                scanf("%d", &c3);
                switch (c3)
                {
                    case 1:
                        insert2();
                        break;

                    case 2:
                        delete2();
                        break;

                    case 3:
                        show(head2);
                        break;

                    case 4:
                        return 0;
                }
            }
    }

    return 0;
}
