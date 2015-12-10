#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=100000+5;

int n,c;//点数,牛栏数
int x[maxn];//n个点的坐标

bool ok(int dist)
{
    int num=1;   //当前选的点数目
    int pre=x[1];//已经选了第1个点
    for(int i=2;i<=n;i++)
    {
        if(x[i]-pre>=dist)//第i个点可以被选
        {
            pre=x[i];
            if(++num >=c) return true;
        }
    }
    return false;
}

int main()
{
    while(scanf("%d%d",&n,&c)==2)
    {
        for(int i=1;i<=n;i++)
            scanf("%d",&x[i]);
        sort(x,x+n);

        //二分处理最小距离
        int L=1,R=1e9;
        while(R>L)
        {
            //使mid更偏向R,否则当R==L+1时,会死循环
            int mid=L+(R-L+1)/2;

            if(ok(mid)) L=mid;
            else R=mid-1;
        }
        printf("%d\n",L);
    }
    return 0;
}