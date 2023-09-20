#include <stdio.h>
int main()
{
    int i,j,n,check,k;
    printf("enter a limit\n");
    scanf("%d",&k);
    scanf("%d",&n);
    for(i=k;i<=n;i++)
    {
        for(j=2;j<i;j++)
        {
            if(i%j==0)
                check=1;
        }
        if(check==0)
            printf("%d\t",i);
        check=0;
    }
    return 0;
}

