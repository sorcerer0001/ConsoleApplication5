#include<stdio.h>
#include<stdio.h>
#include<string.h>
#include<iostream>
using namespace std;
#define MAXN 65536
int que[MAXN*2];
int front,rear;
bool used[MAXN];
int step[MAXN];
bool find0;
void bfs(int p)
{
    find0=false;
    step[p]=0;
    if(p==0||p==65535)
    {
        cout<<"0"<<endl;
        find0=true;
        return;
    } 
    memset(used,false,sizeof(used));
    rear=front=0;
    que[rear++]=p;
    used[p]=true;  
    while(front<rear)
    {
        int tmp=que[front++];
        int t=tmp;
        //step++;
        for(int i=0;i<16;i++)
        {
            tmp=t;
            tmp^=1<<(15-i);
            if(i%4==0)tmp^=1<<(14-i);
            else if(i%4==3)tmp^=1<<(16-i);
            else tmp^=5<<(14-i);
  
            if(i<=3)tmp^=1<<(15-i-4);
            else if(i>=12)tmp^=1<<(15-i+4);
            else 
            {
                tmp^=1<<(15-i-4);tmp^=1<<(15-i+4);
            } 
            if(tmp==0||tmp==65535)
            {
                cout<<step[t]+1<<endl;
                find0=true;
                return;
            }
            if(used[tmp]==false)
            {
                que[rear++]=tmp;
                used[tmp]=true;
                step[tmp]=step[t]+1;
            }           
        }    
    }     
}  
int main()
{
    int i,j;
    char color;
    int id=0;
    for(i=0;i<4;i++)
      for(j=0;j<4;j++)
      {
          cin>>color;
          id<<=1;
          if(color=='b')id+=1;
          
      }  
     bfs(id);
     if(find0==false)
     {
         cout<<"Impossible"<<endl;
     }    
     //system("pause");
     return 0;  
}