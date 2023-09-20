#include<stdio.h>
int main()
{
    int a[30],n,srch,i,temp,j,temp1;
    printf("enter array length\n");
    scanf("%d",&n);
    printf("enter numbers\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    for(i=0;i<n-1;i++)
    {
        temp=i;
        for(j=i+1;j<n;j++)
            {
                if(a[j]<a[temp])
                    {temp=j;}
            }
        if(temp!=i)
        {
            temp1=a[temp];
            a[temp]=a[i];
            a[i]=temp1;
        }
    }
    for(i=0;i<n;i++)
    {
        printf("%d\t",a[i]);
    }
}
