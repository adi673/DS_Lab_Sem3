#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    struct node * leftlink;
    int coef;
    int exp;
    struct node * rightlink;
}node;

node * create(int c, int e, node * prev, node * next)
{
    node * temp = (node *) malloc(sizeof(node));
    temp -> coef = c;
    temp -> exp = e;
    temp -> leftlink = prev;
    temp -> rightlink = next;

    return temp;
}

node * create_poly(int n)
{
    node * first = create(-1, -1, NULL, NULL);
    first -> leftlink = first;
    first -> rightlink = first;
    node * curr = first;

    int i, co, ex;
    for(i = 0; i < n; i++)
    {
        printf("Enter coefficient: ");
        scanf("%d", &co);
        printf("Enter exponent: ");
        scanf("%d", &ex);

        curr -> rightlink = create(co, ex, curr, first);
        curr = curr -> rightlink;
        first -> leftlink = curr;
    }

    return first;
}

void disp(node * ptr)
{
    if(ptr -> rightlink == ptr)
    {
        printf("Polynomial not entered\n");
    }

    else
    {
        node * curr = ptr -> rightlink;
        while(curr != ptr)
        {
            printf("%dx^%d\t", curr -> coef, curr -> exp);
            curr = curr -> rightlink;
            if(curr != ptr)
            {
                printf("+\t");
            }
        }
        printf("\n");
    }
}

node * add(node * x, node * y)
{
    node * z = create(-1, -1, NULL, NULL);
    z -> leftlink = z;
    z -> rightlink = z;
    node * curr = z;
    node * ycurr = y -> rightlink;
    node * xcurr = x -> rightlink;

    while((xcurr != x) && (ycurr != y))
    {
        if(xcurr -> exp == ycurr -> exp)
        {
            if((xcurr -> coef) + (ycurr -> coef))
            {
                curr -> rightlink = create((xcurr -> coef + ycurr -> coef), xcurr -> exp, curr, z);
                curr = curr -> rightlink;
                z -> leftlink = curr;
            }
            xcurr = xcurr -> rightlink;
            ycurr = ycurr -> rightlink;
        }

        else if(xcurr -> exp > ycurr -> exp)
        {
            curr -> rightlink = create(xcurr -> coef, xcurr -> exp, curr, z);
            curr = curr -> rightlink;
            z -> leftlink = curr;
            xcurr = xcurr -> rightlink;
        }

        else
        {
            curr -> rightlink = create(ycurr -> coef, ycurr -> exp, curr, z);
            curr = curr -> rightlink;
            z -> leftlink = curr;
            ycurr = ycurr -> rightlink;
        }
    }

    while(ycurr != y)
    {
        curr -> rightlink = create(ycurr -> coef, ycurr -> exp, curr, z);
        curr = curr -> rightlink;
        z -> leftlink = curr;
        ycurr = ycurr -> leftlink;
    }

    while(xcurr != x)
    {
        curr -> rightlink = create(xcurr -> coef, xcurr -> exp, curr, z);
        curr = curr -> rightlink;
        z -> leftlink = curr;
        xcurr = xcurr -> rightlink;
    }

    return z;
}

int main(void)
{
    int m, n;
    printf("Enter the number of terms in polynomial f(x): ");
    scanf("%d", &n);
    node * a = create_poly(n);

    printf("Enter the number of terms in polynomial g(x): ");
    scanf("%d", &m);
    node * b = create_poly(m);

    node * c = add(a, b);
    disp(c);
}
