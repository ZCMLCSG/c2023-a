#include <raylib.h>
#include <stdlib.h>

_Bool gameOver(int **map)//判断游戏是否结束
{
    int a=0;//用于判断全下满
    for(int i=1;i<=15;i++)
    {
        for(int j=1;j<=15;j++)
        {
           if(map[i][j]!=0)
           {
               a+=1;
               if (map[i][j] == 1 && map[i][j + 1] == 1 &&
                   map[i][j + 2] == 1 && map[i][j + 3] == 1 &&map[i][j + 4] == 1)
               {
                   DrawText("you win!", 150, 300, 60, GREEN);
                   DrawLine(i*50, j*50, i*50, (j+4)*50, GREEN);
                   return true;
               }
               else if (map[i][j] == -1 && map[i][j + 1] == -1 &&
                        map[i][j + 2] == -1 &&map[i][j + 3] == -1 &&map[i][j + 4] == -1)
               {
                   DrawText("you loose!", 150, 300, 60, RED);
                   DrawLine(i*50, j*50, i*50, (j+4)*50, RED);
                   return true;
               }
               else if (map[i][j] == 1 && map[i + 1][j] == 1 &&
                        map[i + 2][j] == 1 &&map[i + 3][j] == 1 &&map[i + 4][j] == 1)
               {
                   DrawText("you win!", 150, 300, 60, GREEN);
                   DrawLine(i*50, j*50, (i+4)*50, j*50, GREEN);
                   return true;
               }
               else if (map[i][j] == -1 && map[i + 1][j] == -1 &&
                        map[i + 2][j] == -1 &&map[i + 3][j] == -1 &&map[i + 4][j] == -1)
               {
                   DrawText("you loose!", 150, 300, 60, RED);
                   DrawLine(i*50, j*50, (i+4)*50, j*50, RED);
                   return true;
               }
               else if (map[i][j] == 1 && map[i + 1][j + 1] == 1 &&
                        map[i + 2][j + 2] == 1 &&map[i + 3][j + 3] == 1 &&map[i + 4][j + 4] == 1)
               {
                   DrawText("you win!", 150, 300, 60, GREEN);
                   DrawLine(i*50, j*50, (i+4)*50, (j+4)*50, GREEN);
                   return true;
               }
               else if (map[i][j] == -1 && map[i + 1][j + 1] == -1 &&
                        map[i + 2][j + 2] == -1 &&map[i + 3][j + 3] == -1 && map[i + 4][j + 4] == -1)
               {
                   DrawText("you loose!", 150, 300, 60, RED);
                   DrawLine(i*50, j*50, (i+4)*50, (j+4)*50, RED);
                   return true;
               }
               else if (map[i][j] == 1 && map[i - 1][j + 1] == 1 &&
                        map[i - 2][j + 2] == 1 &&map[i - 3][j + 3] == 1 &&map[i - 4][j + 4] == 1)
               {
                   DrawText("you win!", 150, 300, 60, GREEN);
                   DrawLine(i*50, j*50, (i-4)*50, (j+4)*50, GREEN);
                   return true;
               }
               else if (map[i][j] == -1 && map[i - 1][j + 1] == -1 &&
                        map[i - 2][j + 2] == -1 &&map[i - 3][j + 3] == -1 && map[i - 4][j + 4] == -1)
               {
                   DrawText("you loose!", 150, 300, 60, RED);
                   DrawLine(i*50, j*50, (i-4)*50, (j+4)*50, RED);
                   return true;
               }
           }
           if(a==225)//平局
           {
               DrawText("both win!",150,300,60,YELLOW);
               return true;
           }
        }
    }
    return false;
}

void paint(int **map,int **mark) {//画棋盘、棋子和红点标注
    ClearBackground(BROWN);
    for(int i=1;i<16;i++){
        DrawLine(i*50,50,i*50,750,BLACK);
    }
    for(int i=1; i <16; i++){
        DrawLine(50, i*50, 750, i*50, BLACK);
    }
    DrawCircle(4*50,4*50,8,BLACK);
    DrawCircle(12*50,4*50,8,BLACK);
    DrawCircle(4*50,12*50,8,BLACK);
    DrawCircle(12*50,12*50,8,BLACK);
    DrawCircle(8*50,8*50,8,BLACK);
    for(int i=1;i<16;i++)
    {
        for(int j=1;j<16;j++)
        {
            if(map[i][j]==1)
            {
                DrawCircle(i*50,j*50,20,BLACK);
            }
            else if(map[i][j]==-1)
            {
                DrawCircle(i*50,j*50,20,WHITE);
            }
        }
    }
    for(int i=1;i<16;i++)
    {
        for(int j=1;j<16;j++)
        {
            if(mark[i][j]==1||mark[i][j]==-1)
            {
                DrawCircle(i*50,j*50,5,RED);
            }
        }
    }
    if(gameOver(map))
    {
        DrawText("See you next time!",150,400,60,GREEN);
    }
}

bool ismapempty(int **map)//判断是否为空
{
    for(int i=1;i<=15;i++)
    {
        for(int j=1;j<=15;j++)
        {
            if(map[i][j]!=0)return true;
        }
    }
    return false;
}

void clear(int **score)//清空数组
{
    for(int i=1;i<16;i++)
    {
        for(int j=1;j<16;j++)
        {
            score[i][j]=0;
        }
    }
}

int Scores(int a,int b,int c)//对应的分数
{
    if(c==-1)
    {
        if(a==0&&b==0)return 20;
        if(a==0&&b==1)return 10;
        if(a==0&&b==2)return 6;
        if(a==1&&b==0)return 100;
        if(a==1&&b==1)return 40;
        if(a==1&&b==2)return 20;
        if(a==2&&b==0)return 600;
        if(a==2&&b==1)return 200;
        if(a==2&&b==2)return 100;
        if(a==3&&b==0)return 3000;
        if(a==3&&b==1)return 600;
        if(a==3&&b==2)return 200;
        if(a==4&&b==0)return 15000;
        if(a==4&&b==1)return 15000;
        if(a==4&&b==2)return 15000;
        return 0;
    }
    else
    {
        if(a==0&&b==0)return 20;
        if(a==0&&b==1)return 10;
        if(a==0&&b==2)return 6;
        if(a==1&&b==0)return 100;
        if(a==1&&b==1)return 40;
        if(a==1&&b==2)return 20;
        if(a==2&&b==0)return 600;
        if(a==2&&b==1)return 200;
        if(a==2&&b==2)return 100;
        if(a==3&&b==0)return 5000;
        if(a==3&&b==1)return 800;
        if(a==3&&b==2)return 200;
        if(a==4&&b==0)return 20000;
        if(a==4&&b==1)return 20000;
        if(a==4&&b==2)return 20000;
        return 0;
    }
}

int calculate_scores(int **map,int r,int c)
{
    int point=0;
    int self=0;
    int other=0;
    for(int a=-1;a<=1;a++)
    {
        if(a!=0)//两方分数均计算使得估值更加合理
        {
            for(int i=c-1;i>=1;i--)
            {
                if(map[r][i]==a)
                {
                    self++;
                }
                else if(map[r][i]==0)
                {
                    break;
                }
                else
                {
                    other++;
                    break;
                }
            }
            for(int i=c+1;i<=15;i++)
            {
                if(map[r][i]==a)
                {
                    self++;
                }
                else if(map[r][i]==0)
                {
                    break;
                }
                else
                {
                    other++;
                    break;
                }
            }
            point+=Scores(self,other,a);
            self=0;
            other=0;
            for(int i=r-1;i>=1;i--)
            {
                if(map[i][c]==a)
                {
                    self++;
                }
                else if(map[i][c]==0)
                {
                    break;
                }
                else
                {
                    other++;
                    break;
                }
            }
            for(int i=r+1;i<=15;i++)
            {
                if(map[i][c]==a)
                {
                    self++;
                }
                else if(map[i][c]==0)
                {
                    break;
                }
                else
                {
                    other++;
                    break;
                }
            }
            point+=Scores(self,other,a);
            self=0;
            other=0;
            for(int i=r+1,k=c-1;i<=15&&k>=1;i++,k--)
            {
                if(map[i][k]==a)
                {
                    self++;
                }
                else if(map[i][k]==0)
                {
                    break;
                }
                else
                {
                    other++;
                    break;
                }
            }
            for(int i=r-1,k=c+1;i>=1&&k<=15;i--,k++)
            {
                if(map[i][k]==a)
                {
                    self++;
                }
                else if(map[i][k]==0)
                {
                    break;
                }
                else
                {
                    other++;
                    break;
                }
            }
            point+=Scores(self,other,a);
            self=0;
            other=0;
            for(int i=r+1,k=c+1;i<=15&&k<=15;i++,k++)
            {
                if(map[i][k]==a)
                {
                    self++;
                }
                else if(map[i][k]==0)
                {
                    break;
                }
                else
                {
                    other++;
                    break;
                }
            }
            for(int i=r-1,k=c-1;i>=1&&k>=1;i--,k--)
            {
                if(map[i][k]==a)
                {
                    self++;
                }
                else if(map[i][k]==0)
                {
                    break;
                }
                else
                {
                    other++;
                    break;
                }
            }
            point+=Scores(self,other,a);
            self=0;
            other=0;
        }
    }
    return point;
}

void record_Scores(int **map,int **score){//记录分数
    for(int i=1;i<=15;i++)
    {
        for(int j=1;j<=15;j++)
        {
            if(map[i][j]==0)
            {
                score[i][j]= calculate_scores(map,i,j);
            }
        }
    }
}

typedef struct//用于悔棋
{
    int data[227];
    int top;
}Stack;

bool initStack(Stack *a)//初始化
{
    (*a).top=0;
    for(int i =0;i<=225;i++)
    {
        (*a).data[i]=0;
    }
    return true;
}

bool push(Stack *a,int x)//进
{
    (*a).top++;
    (*a).data[(*a).top]=x;
    return true;
}

bool pop(Stack *a,int *b)//出
{
    *b=(*a).data[(*a).top];
    (*a).top--;
    return true;
}

void AIdrawpiece(int **map,int **score,Stack *a,int **mark) {//电脑落子
    record_Scores(map,score);
    int max = 0;
    int b = 0;
    int e[16][16] = {};
    for (int row = 1; row <=15; row++) {
        for (int col = 1; col <=15; col++) {
            if (map[row][col] == 0) {
                if (score[row][col] > max) {
                    max = score[row][col];
                }
            }
        }
    }
    for(int row=1;row<=15;row++)
    {
        for(int col=1;col<=15;col++)
        {
            if(map[row][col]==0)
            {
                if(score[row][col]==max)
                {
                    e[row][col]=1;
                    b++;
                }
            }
        }
    }
    int c;
    int d=0;
    c=rand()%b;
    if(c==0)
    {
        c=1;
    }
    for(int row=1;row<=15;row++)
    {
        for (int col = 1; col <=15; col++)
        {
            if(e[row][col]==1)
            {
                d++;
            }
            if(c==d)
            {
                if(map[row][col]==0)
                {
                    map[row][col]=-1;
                    push(a,((col-1)*15+row));
                    mark[row][col]=-1;
                }
                goto a;
            }
        }
    }
    a:
}

int main() {
    Stack s,*a=&s;
    initStack(a);
    const int width = 800;
    const int height = 800;
    int map[17][17] = {};
    int *p[17] = {map[0], map[1], map[2], map[3], map[4], map[5], map[6],
                  map[7],map[8], map[9], map[10], map[11], map[12],
                  map[13], map[14],map[15],map[16]};
    int score[16][16] = {};
    int *p1[16] = {score[0], score[1], score[2], score[3], score[4], score[5], score[6], score[7],
                   score[8], score[9], score[10], score[11], score[12], score[13], score[14],score[15]};
    int mark[16][16]={};
    int *p2[16] = {mark[0],mark[1],mark[2],mark[3],mark[4],mark[5],mark[6],mark[7],
                   mark[8],mark[9],mark[10],mark[11],mark[12],mark[13],mark[14],mark[15]};
    InitWindow(width, height, "Chess");
    while (!WindowShouldClose()) {
        BeginDrawing();
        paint(p,p2);
        if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)&&!gameOver(p))//玩家落子
        {
            int x,y;
            x = GetMouseX();
            y = GetMouseY();
            if (x >= 25 && y >= 25 && x <= 775 && y <= 775)//用于模糊定位
            {
                if (x < 50 && y < 50)
                {
                    x = 50;
                    y = 50;
                }
                else if (x < 50 && y >= 50)
                {
                    x = 50;
                    if (y % 50 < 25)
                    {
                        y = y - (y % 50);
                    }
                    else
                    {
                        y = y - (y % 50) + 50;
                    }
                }
                else if (x >= 50 && y < 50)
                {
                    y = 50;
                    if (x % 50 < 25)
                    {
                        x = x - (x % 50);
                    }
                    else
                    {
                        x = x - (x % 50) + 50;
                    }
                }
                else
                {
                    if (x % 50 < 25)
                    {
                        x = x - (x % 50);
                    }
                    else
                    {
                        x = x - (x % 50) + 50;
                    }
                    if (y % 50 < 25)
                    {
                        y = y - (y % 50);
                    }
                    else
                    {
                        y = y - (y % 50) + 50;
                    }
                }
                if (map[x / 50][y / 50] == 0)
                {
                    clear(p2);
                    map[x / 50][y / 50] = 1;
                    push(a,((y/50-1)*15+x/50));
                    mark[x / 50][y / 50] = 1;
                   if(!gameOver(p))
                   {
                       AIdrawpiece(p, p1,a,p2);//电脑落子
                       clear(p1);
                   }
                }
            }
        }
        else if(IsMouseButtonPressed(MOUSE_BUTTON_RIGHT)&&ismapempty(p))//玩家悔棋
        {
            int b=0,*c=&b;
            int b1=0,*c1=&b1;
            int i=0,j=0;
            pop(a,c);
            if(b%15!=0)
            {
                i=b%15;
                j=(b-i)/15+1;
                map[i][j]=0;
            }
            else
            {
                j=b/15;
                map[15][j]=0;
            }
            pop(a,c1);
            if(b1%15!=0)
            {
                i=b1%15;
                j=(b1-i)/15+1;
                map[i][j]=0;
            }
            else
            {
                j=b1/15;
                map[15][j]=0;
            }
        }
        paint(p,p2);
        EndDrawing();
    }
}