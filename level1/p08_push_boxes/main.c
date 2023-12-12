#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include<windows.h>
void move(char**a){
    int x, y, z, boxes;
    x = 1;
    y = 1;
    z = 0;
    boxes = 3;
    system("cls");
    while (1)
    {
        printf("you have moved for %d/100 times\n", z);
        if (boxes == 0)
        {
            printf("you did a good djob!\n",z);
            break;
        }
        if (z == 100)
        {
            printf("OMG!you moved for so many times!(100 times)\nyou loose!!\n");
            Sleep(3000);
            break;
        }
        for (int i = 0; i < 11; i++)
        {
            for (int c = 0; c < 16; c++)
            {
                printf("%c", a[i][c]);
            }
            printf("\n");
        }
        char move = getch();
        if (move == 'w')
        {
            if (a[x - 1][y] != '#' && a[x - 1][y] != 'b' && a[x - 1][y] != 'c')
            {
                a[x][y] = ' ';
                x--;
                a[x][y] = 'a';
                z++;
            } else if (a[x - 2][y] != '#' && a[x - 1][y] == 'b')
            {
                if (a[x - 2][y] == ' ')
                {
                    a[x][y] = ' ';
                    x--;
                    a[x][y] = 'a';
                    a[x - 1][y] = 'b';
                    z++;
                } else if (a[x - 2][y] == 'c')
                {
                    a[x][y] = ' ';
                    x--;
                    a[x][y] = 'a';
                    boxes--;
                    z++;
                }
            }
        } else if (move == 's')
        {
            if (a[x + 1][y] != '#' && a[x + 1][y] != 'b' && a[x + 1][y] != 'c')
            {
                a[x][y] = ' ';
                x++;
                a[x][y] = 'a';
                z++;
            } else if (a[x + 2][y] != '#' && a[x + 1][y] == 'b')
            {
                if (a[x + 2][y] == ' ')
                {
                    a[x][y] = ' ';
                    x++;
                    a[x][y] = 'a';
                    a[x + 1][y] = 'b';
                    z++;
                } else if (a[x + 2][y] == 'c')
                {
                    a[x][y] = ' ';
                    x++;
                    a[x][y] = 'a';
                    boxes--;
                    z++;
                }
            }
        } else if (move == 'a')
        {
            if (a[x][y - 1] != '#' && a[x][y - 1] != 'b' && a[x][y - 1] != 'c')
            {
                a[x][y] = ' ';
                y--;
                a[x][y] = 'a';
                z++;
            } else if (a[x][y - 2] != '#' && a[x][y - 1] == 'b')
            {
                if (a[x][y - 2] == ' ')
                {
                    a[x][y] = ' ';
                    y--;
                    a[x][y] = 'a';
                    a[x][y - 1] = 'b';
                    z++;
                } else if (a[x][y - 2] == 'c')
                {
                    a[x][y] = ' ';
                    y--;
                    a[x][y] = 'a';
                    boxes--;
                    z++;
                }
            }
        } else if (move == 'd')
        {
            if (a[x][y + 1] != '#' && a[x][y + 1] != 'b' && a[x][y + 1] != 'c')
            {
                a[x][y] = ' ';
                y++;
                a[x][y] = 'a';
                z++;
            } else if (a[x][y + 2] != '#' && a[x][y + 1] == 'b')
            {
                if (a[x][y + 2] == ' ')
                {
                    a[x][y] = ' ';
                    y++;
                    a[x][y] = 'a';
                    a[x][y + 1] = 'b';
                    z++;
                } else if (a[x][y + 2] == 'c')
                {
                    a[x][y] = ' ';
                    y++;
                    a[x][y] = 'a';
                    boxes--;
                    z++;
                }
            }
        }
        system("cls");
    }
}
int main()
{
    char a[51][51]={};
    FILE *map=fopen("D:\\c2023\\class\\map1.txt","r");
    if(map!=NULL)
    {
        for (int i = 0; i < 11; i++)
        {
            for (int j = 0; j < 15; j++)
            {
                char k = fgetc(map);
                a[i][j] = k;
            }
        }
    }
    fclose(map);
    char*p[51]={a[0],a[1],a[2],a[3],a[4],a[5],a[6],a[7],a[8],a[9],a[10],a[11]};
    printf("w,s,a,d control the move of letter'a'\npush the 'b's into the 'c's!\n");
    Sleep(4000);
    move(p);
    printf("there will be the second map!");
    Sleep(3000);
    char b[51][51]={};
    FILE *map2=fopen("D:\\c2023\\class\\map2.txt","r");
    if(map2!=NULL)
    {
        for (int i = 0; i < 11; i++)
        {
            for (int j = 0; j < 15; j++)
            {
                char m = fgetc(map2);
                b[i][j] = m;
            }
        }
    }
    fclose(map2);
    char*p1[50]={b[0],b[1],b[2],b[3],b[4],b[5],b[6],b[7],b[8],b[9],b[10],b[11]};
    move(p1);
    Sleep(3000);
}
