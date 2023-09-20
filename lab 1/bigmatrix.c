#include<stdio.h>
int main()
{
    int a[20][20],b[20][20],c[20][20],k,l,m,n,i,j;
    printf("enter dimensions of a \n");
    scanf("%d%d",&k,&l);
    printf("enter dimensions of b \n");
    scanf("%d%d",&m,&n);
    printf("enter matrix a\n");
    for(i=0;i<k;i++)
    {
        for(j=0;j<l;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
    printf("enter matrix b\n");
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            scanf("%d",&b[i][j]);
        }
    }
    printf("enter matrix a\n");
    for(i=0;i<k;i++)
    {
        for(j=0;j<l;j++)
        {
            if(a[i][j]>b[i][j])
            {
                c[i][j]=a[i][j];
            }
            else
                c[i][j]=b[i][j];
        }
    }
    for(i=0;i<k;i++)
    {
        for(j=0;j<l;j++)
        {
            printf("%d\t",c[i][j]);
        }
        printf("\n");
    }
}
