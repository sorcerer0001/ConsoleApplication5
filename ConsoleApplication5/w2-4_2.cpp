#include<cstdio>  
#include<cstring>  
#define max(a,b) a>b?a:b  
int main()  
{  
    int m,n,i,j,c[20000],w[4000],p[4000];  
    scanf("%d%d",&n,&m);  
    for(i=0;i<n;i++)  
        scanf("%d%d",&w[i],&p[i]);  
    memset(c,0,sizeof(c));  
    for(i=0;i<n;i++)  
        for(j=m;j>=w[i];j--)  
            c[j]=max(c[j],c[j-w[i]]+p[i]);  
    printf("%d\n",c[m]);  
    return 0;  
}  