#include<string.h>
#include<stdio.h>
#include<windows.h>
void encryption(char a[],int d)
{
    int c=strlen(a);
    for(int i=0;i<c;i++)
    {
        a[i]=a[i]+d;
    }
    printf("加密后的密文为:\n");
    for(int i=0;i<c-1;i++)
    {
        printf("%c",a[i]);
    }
    printf("%c\n",a[c-1]);
}
void decrypt(char a[],int k)
{
    int c=strlen(a);
    for(int i=0;i<c;i++)
    {
        a[i]=a[i]-k;
    }
    printf("解密后的明文为:");
    for(int i=0;i<c-1;i++)
    {
        printf("%c",a[i]);
    }
    printf("%c\n",a[c-1]);
}
int main()
{
    char b;
    char a[100];
    printf("请输入明文:");
    gets(a);
    int d;
    printf("请设定密钥(数字):");
    scanf("%d",&d);
    encryption(a,d);
    int k;
    printf("请输入密钥:");
    scanf("%d",&k);
    if(d==k)
    {
        decrypt(a,d);
        Sleep(3000);
    }
    else
    {
        printf("密钥错误！\n");
        Sleep(3000);
    }
}
