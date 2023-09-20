#include <stdio.h>
int main()
{
    int a[30],n,srch,i,check=0,j,low,high,mid,temp;
    printf("enter array length\n");
    scanf("%d",&n);
    printf("enter numbers\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    printf("enter the search");
    scanf("%d",&srch);
    //sort
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
    //
    high=n-1;
    low=0;
    while(low<=high)
    {
     mid=(high+low)/2;
     if(a[mid]==srch)
        {
            printf("number found");
            return 0;
        }
     else if(a[mid]>srch)
        {
            high=mid-1;
        }
     else
            low=mid+1;
    }
}


