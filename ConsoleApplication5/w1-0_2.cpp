#include <stdio.h>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <math.h>
#include <string.h>
#define LL long long
#define _LL __int64

using namespace std;
const int INF = 0x3f3f3f3f;

char mapp[17][17];
int a[16*16][16*16];
int equ,var;
int x[16*16];
int free_x[16*16]; //保存自由变元，枚举求最优解
int free_num;

void init()
{
    memset(a,0,sizeof(a));
    memset(x,0,sizeof(x));
}

void debug()
{
    for(int i = 0; i < equ; i++)
    {
        for(int j = 0; j < var+1; j++)
            printf("%d",a[i][j]);
        printf("\n");
    }
}

int Gauss()
{
	int row,col,i,j;
	int max_r;

	row = col = 0;
	free_num = 0;
	while(row < equ && col < var)
	{
		max_r = row;
		for(i = row+1; i < equ; i++)
		{
			if( abs(a[i][col]) > abs(a[max_r][col]) )
				max_r = i;
		}

		if(max_r != row)
		{
			for(j = col; j < var+1; j++)
				swap(a[max_r][j],a[row][j]);
		}
		if(a[row][col] == 0)
		{
			free_x[ free_num++ ] = col; //该列对应的变量是自由元
			col++;
			continue;
		}

		for(i = row+1; i < equ; i++)
		{
			if(a[i][col] == 0) continue;
			for(j = col; j < var+1; j++)
				a[i][j] ^= a[row][j];
		}
		row++;
		col++;
	}

	for(i = row; i < equ; i++)
		if(a[i][col] != 0)
			return -1; //无解

	if(row < var)
		return var-row; //返回自由变元的数目

	for(i = var-1; i >= 0; i--) //有唯一解
	{
		x[i] = a[i][var];
		for(j = i+1; j < var; j++)
			x[i] ^= (a[i][j] && x[j]);
	}
	return 0;
}

void solve()
{
	int t = Gauss();
	if(t == -1)
	{
		printf("inf\n");
		return;
	}
	else if(t == 0)
	{
		int ans = 0;
		for(int i = 0; i < var; i++)
			ans += x[i];
		printf("%d\n",ans);
		return;
	}
	else
	{
		int ans = INF;
		int sta = (1<<t); //t个变量共有sta个基础解
		int cnt;

		for(int i = 0; i < sta; i++)
		{
			cnt = 0;
			//先给自由变元赋值
			for(int j = 0; j < t; j++)
			{
				if((1<<j) & i)
				{
					x[ free_x[j] ] = 1;
					cnt++;
				}
				else
					x[ free_x[j] ] = 0;
			}
            //求出其他的解
			for(int j = var-t-1; j >= 0; j--)
			{
				int l,k;

				for(k = j; k < var; k++)
					if(a[j][k])
						break; //先找到该行第一个不为0的数
				x[k] = a[j][var];

				for(l = k+1; l < var; l++)
					x[k] ^= (x[l] && a[j][l]);
				cnt += x[k];
			}

			ans = min(ans,cnt);
		}
		printf("%d\n",ans);
		return;
	}
}

int main()
{
    int n,test;

    scanf("%d",&test);
    while(test--)
    {
        init();
        scanf("%d",&n);

        equ = var = n*n;

        for(int i = 0; i < n; i++)
            scanf("%s",mapp[i]);

        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(mapp[i][j] == 'w')
					a[i*n+j][var] = 1;
                else a[i*n+j][var] = 0;
            }
        }
		for(int i = 0; i < equ; i++)
		{
			int x = i/n;
			int y = i%n;

			for(int j = 0; j < var; j++)
			{
				int xx = j/n;
				int yy = j%n;
				if( abs(x-xx) + abs(y-yy) <= 1)
					a[i][j] = 1;
				else a[i][j] = 0;
			}
		}
		solve();
    }
    return 0;
}
