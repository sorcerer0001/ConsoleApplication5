#include<stdio.h>
#include<string.h>
int ans,m,n,vis[1000000],step[10],now[10],num;
char s[10];
void dfs(int pos,int sum,int cnt)
{
    int i,t;
    if(pos>=m){
        vis[sum]++;
        if(sum>ans){
            ans=sum;  //记录最佳切割的和
            num=cnt;
            for(i=0;i<cnt;i++) //记录当前最佳方案
                step[i]=now[i];
        }
        return ;
    }
    t=0;
    for(i=pos;i<m;i++){
        t=t*10+s[i]-'0';
        if(sum+t>n)
            return ;
        now[cnt]=t;
        dfs(i+1,sum+t,cnt+1);
    }
}
int main()
{
    int i,sum;
    while(scanf("%d%s",&n,s)!=EOF){
        m=strlen(s);
        if(n==0&&s[0]=='0'&&m==1)
            break;
        sum=0;
        for(i=0;i<m;i++)
            sum+=s[i]-'0';
        if(sum>n){   //若最小的和都大于targe,则肯定不可能切割出不超过targe的和
            printf("error\n");
            continue;
        }
        memset(vis,0,sizeof(vis));
        num=ans=0;
        dfs(0,0,0);
        if(vis[ans]>1)
            printf("rejected\n");
        else{
            printf("%d",ans);
            for(i=0;i<num;i++)
                printf(" %d",step[i]);
            printf("\n");
        }
    }
    return 0;
}