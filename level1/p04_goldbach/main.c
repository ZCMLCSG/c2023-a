#include<stdio.h>
int main()
{
    int a,i,c,f;
    f=0;
    for(a=2;a<=100;a=a+2)
    {
        for(i=1;i<=(a/2);i++)
        {
            c=a-i;
            int k,d;
            for(k=2;k<=i-1;k++)
            {
                if(i%k==0)
                    break;
            }
            if(k>=i)
            {
                for(d=2;d<=c-1;k++)
                {
                    if(c%k==0)
                        break;
                }
                if(k>=c)
                {
                    f=f+1;
                    break;
                }
            }
        }
    }
    printf("%d\n",f);
    if(f==50)
    {
        printf("The Goldbach conjecture is right!");
    }
    else
    {
        printf("The Goldbach conjecture is wrong!");
    }
    return 0;
}
