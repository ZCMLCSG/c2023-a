#include <stdio.h>
#include <time.h>
int main()
{
    int i,a;
    double start,finish;
    start=clock();
    for(a=2;a<=1000;a++)
    {
        for(i=2;i<=a-1;i++)
        {
            if(a%i==0)
                break;
        }
        if(i>=a)
        {
            printf("%d\n",a);
        }
    }
    finish=clock();
    printf("%f seconds\n",(finish-start)/CLOCKS_PER_SEC);
}
