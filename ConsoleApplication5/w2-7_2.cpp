#include<iostream>
using namespace std;
int map[5][5];
int dx[4]={1,-1,0,0};
int dy[4]={0,0,-1,1};
int front=0,rear=1;
struct node{
    int x,y,pre;
}q[100];

void print(int i)//输出过程
{
    if(q[i].pre!=-1)
    {
        print(q[i].pre);
        cout<<"("<<q[i].x<<", "<<q[i].y<<")"<<endl;
    }
}
void bfs(int x1,int y1)//广搜
{
    q[front].x=x1;
    q[front].y=y1;
    q[front].pre=-1;
    while(front<rear)//当队列不空
    {
        for(int i=0;i<4;i++)//搜索可达的路径
        {
            int a=dx[i]+q[front].x;
            int b=dy[i]+q[front].y;
            if(a<0||a>=5||b<0||b>=5||map[a][b])//是否在迷宫内，是否可行
                continue;
            else 
            {
                map[a][b]=1; //走过的路做标记
                q[rear].x=a;
                q[rear].y=b;
                q[rear].pre=front;
                rear++; //入队
            }
            if(a==4&&b==4) print(front); 
        }
        front++;//出队
    }
}

int main()
{
    int i,j;
    for(i=0;i<5;i++)
        for(j=0;j<5;j++)
            cin>>map[i][j];
    cout<<"(0, 0)"<<endl;
    bfs(0, 0);
    cout<<"(4, 4)"<<endl;
    return 0;
}