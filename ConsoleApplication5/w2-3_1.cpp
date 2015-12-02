//编程题＃1：集合加法

/*
使用有序容器
枚举
控制条件为录入的需要求和的值
*/
//以下非上述实现


#include <stdio.h>
#include <stdlib.h>
int compare(const void *e1,const void *e2)
{
    return *(int*)e1-*(int*)e2;
    }

int main()
{
    int n;
    scanf("%d",&n);
    while(n--)
    {
        int s,sum=0;
        scanf("%d",&s);
        int pa,pb,i,j;
        scanf("%d",&pa);
        int *a=(int*)malloc(sizeof(int)*pa);
        for(i=0;i<pa;i++) scanf("%d",&a[i]);
        qsort(a,pa,sizeof(int),compare);
        scanf("%d",&pb);
        int *b=(int*)malloc(sizeof(int)*pb);
        for(i=0;i<pb;i++) scanf("%d",&b[i]);
        qsort(b,pb,sizeof(int),compare);
        for(i=0;i<pa;i++)
            for(j=pb-1;j>=0;j--)
            {
                if(a[i]+b[j]==s) sum++;
                }
        printf("%d\n",sum);
        }
    return 0;
}