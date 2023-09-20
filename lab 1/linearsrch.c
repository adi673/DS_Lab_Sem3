#include <stdio.h>
int main()
{
    int a[30],n,srch,i,check=0;
    printf("enter array length\n");
    scanf("%d",&n);
    printf("enter numbers\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    printf("enter the search");
    scanf("%d",&srch);
    for(i=0;i<n;i++)
    {
        if(a[i]==srch)
        {
            check=1;
        }
    }
    if(check==1)
        printf("number is present");
    else
        printf("number is absent");
    return 0;
}
