#include <stdlib.h>
#include<stdio.h>
#include<windows.h>
int main()
{
    int i;
    int x=0;
    int a=30;
    int b=1;
    while(1)
    {
        x=x+b;
        system("cls");
        for (i=0;i<x;i++)
        {
            printf(" ");
        }
        printf("A");
        Sleep(50);
        if(x==a)
            b=-b;
        if(x==0)
            b=-b;
    }
}
