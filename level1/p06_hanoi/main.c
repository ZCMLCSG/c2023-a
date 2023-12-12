#include<stdio.h>
#include<windows.h>
void move(char A,char C)
{
    printf("%c->%c\n",A,C);
}
void HanoTower(char A,char B,char C,int n)
{
    if(n==1)
    {
        move(A,C);
    }
    else
    {
        HanoTower(A,C,B,n-1);
        move(A,C);
        HanoTower(B,A,C,n-1);
    }
}
int main()
{
    int n=0;
    printf("请输入A柱子上圆盘的个数：\n");
    scanf("%d",&n);
    HanoTower('A','B','C',n);
    Sleep(5000);
    return 0;
}
