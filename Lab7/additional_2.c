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

node * merge(int n, node * x, node * y)
{
    node * z = NULL;
    node * curr = NULL;
    int i;

    while((x != NULL) && (y != NULL))
    {
        if((x -> data) < ( y -> data))
        {
            if(z == NULL)
            {
                curr = x;
                x = x -> next;
                curr -> next = NULL;
                z = curr;
            }

            else
            {
                curr -> next = x;
                x = x -> next;
                curr = curr -> next;
                curr -> next = NULL;
            }
        }

        else
        {
            if(z == NULL)
            {
                curr = y;
                y = y -> next;
                curr -> next = NULL;
                z = curr;
            }

            else
            {
                curr -> next = y;
                y = y -> next;
                curr = curr -> next;
                curr -> next = NULL;
            }
        }
    }

    while(x != NULL)
    {
        if(z == NULL)
        {
            curr = x;
            x = x -> next;
            curr -> next = NULL;
            z = curr;
        }

        else
        {
            curr -> next = x;
            x = x -> next;
            curr = curr -> next;
            curr -> next = NULL;
        }
    }

    while(y != NULL)
    {
        if(z == NULL)
        {
            curr = y;
            y = y -> next;
            curr -> next = NULL;
            z = curr;
        }

        else
        {
            curr -> next = y;
            y = y -> next;
            curr = curr -> next;
            curr -> next = NULL;
        }
    }

    return z;
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
    do
    {
        printf("Enter number of nodes in list y: ");
        scanf("%d", &q);
    }
    while(q != p);
    printf("Enter data for y: \n");
    b = create(q);
    disp(b);
    printf("\n");

    c = merge(p, a, b);
    printf("New List is : \n");
    disp(c);
}
