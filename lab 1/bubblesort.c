#include <stdio.h>
int main()
{
    int a[30],n,srch,i,temp,j;
    printf("enter array length\n");
    scanf("%d",&n);
    printf("enter numbers\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    for(j=0;j<n-1;j++)
    {
        for(i=0;i<n-j-1;i++)
        {
            if(a[i]>a[i+1])
            {
            temp=a[i];
            a[i]=a[i+1];
            a[i+1]=temp;
            }
        }
    }
    for(i=0;i<n;i++)
    {
        printf("%d\t",a[i]);
    }
    return 0;
}
