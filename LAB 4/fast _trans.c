#include<stdio.h>
#define m 3
#define n 4
typedef struct{
    int row;
    int col;
    int val;
}sparse;
sparse s[10],s0[10];
void transpose(sparse a[10],sparse b[10])
{
    int non_zero[10]={0},starting_pos[10],i,j;
    b[0].row=a[0].col;
    b[0].col=a[0].row;
    b[0].val=a[0].val;
    for(i=1;i<=a[0].val;i++)
        non_zero[a[i].col]++;
    starting_pos[0]=1;
    for(i=1;i<=b[0].row;i++)
        starting_pos[i]=starting_pos[i-1]+non_zero[i-1];
    for(i=1;i<=a[0].val;i++)
    {
        j=starting_pos[a[i].col]++;
        b[j].row=a[i].col;
        b[j].col=a[i].row;
        b[j].val=a[i].val;
    }
}
void disp(sparse a[10])
{
    printf("row\tcol\tval\n");
    for(int i=0;i<=a[0].val;i++)
        printf("%d\t%d\t%d\n",a[i].row,a[i].col,a[i].val);
}
int main()
{
    int a[10][10],i,j,count=0,k=0;
    for(i=0;i<m;i++)
        for(j=0;j<n;j++)
        scanf("%d",&a[i][j]);
    s[0].row=m;
    s[0].col=n;
    for(i=0;i<m;i++)
        for(j=0;j<n;j++)
            if(a[i][j]!=0)
            {
                k++;
                s[k].row=i;
                s[k].col=j;
                s[k].val=a[i][j];
            }
    s[0].val=k;
    transpose(s,s0);
    disp(s0);
}
