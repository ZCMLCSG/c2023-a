#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include<windows.h>
int main()
{
    char a[50][50]=
            {"############",
             "#a   #   # #",
             " #     ## ##",
             "#  #  #    #",
             "# #  #  ## #",
             "#  # # ##  #",
             " #      # ##",
             "#  ##  ##  b",
             "## #     ###",
             "#     #    #",
             " ########## "
            };
    int x,y,endx,endy;
    x=1;
    y=1;
    endx=7;
    endy=11;
    printf("w,s,a,d control the move of letter'a'");
    Sleep(4000);
    system("cls");
    while(1)
    {
        if(x==endx&&y==endy)
        {
            printf("you win the game!!");
            Sleep(2000);
            break;
        }
        for(int i=0;i<11;i++)
        {
            for(int c=0;c<12;c++)
            {
                printf("%c",a[i][c]);
            }
            printf("%c\n",a[i][12]);
        }
        char move=getch();
        if(move=='w')
        {
            if(a[x-1][y]!='#')
            {
                a[x][y]=' ';
                x--;
                a[x][y]='a';
            }
        }
        if(move=='s')
        {
            if(a[x+1][y]!='#')
            {
                a[x][y]=' ';
                x++;
                a[x][y]='a';
            }
        }
        if(move=='a')
        {
            if(a[x][y-1]!='#')
            {
                a[x][y]=' ';
                y--;
                a[x][y]='a';
            }
        }
        if(move=='d')
        {
            if(a[x][y+1]!='#')
            {
                a[x][y]=' ';
                y++;
                a[x][y]='a';
            }
        }
        system("cls");
    }
    return 0;
}
