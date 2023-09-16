#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i,n;
    scanf("%d",&n);
    for(i=2;i<=n-1;i++)
    {
        if(n%i==0)
            break;
    }
    if(i>=n){
        printf("It is a prime\n");
    }else
        printf("It is not a prime");

    return 0;
}
