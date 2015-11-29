#include <iostream>
#include <cstdio>
using namespace std;
int state[5][5] = {0};
int s[5][5] = {0};
int swit[5][5] = {0};
int cop[5][5] = {0};
int sum = 0;
int mi = 100;
 
void changeswit(int a, int b, int t)
{
    int no = (a - 1) * 3 + b;
    if(b == 2 && a != 2)
    {
        state[a][b - 1] = (state[a][b - 1] + t) % 4;
        state[a][b] = (state[a][b] + t) % 4;
        state[a][b + 1] = (state[a][b + 1] + t) % 4;
    }
    else if(a == 2 && b != 2)
    {
        state[a - 1][b] = (state[a - 1][b] + t) % 4;
        state[a][b] = (state[a][b] + t) % 4;
        state[a + 1][b] = (state[a + 1][b] + t) % 4;
    }
    else if(a == 2 && b == 2)
    {
        state[a][b] = (state[a][b] + t) % 4;
        state[a - 1][b] = (state[a - 1][b] + t) % 4;
        state[a + 1][b] = (state[a + 1][b] + t) % 4;
        state[a][b - 1] = (state[a][b - 1] + t) % 4;
        state[a][b + 1] = (state[a][b + 1] + t) % 4;
    }
    else
    {
        int dx[3] = {-1, 0, 1};
        int dy[3] = {-1, 0, 1};
        for(int i = 0; i < 3; i++)
            for(int j = 0; j < 3; j++)
                state[a+dx[i]][b+dy[j]] = (state[a+dx[i]][b+dy[j]] + t) % 4;
    }
    return;
 
}
 
 
int main()
{
    for(int i = 1; i <= 3; i++)
        for(int j = 1; j <= 3; j++)
            scanf("%d",&s[i][j]);
    for(int i = 0; i < 4; i++)
    {
        for(int j = 0; j < 4; j++)
        {
            for(int k = 0; k < 4; k++)
            {
                for(int l = 1; l < 4; l++)
                    for(int m = 1; m < 4; m++)
                    {
                        state[l][m] = s[l][m];
                        swit[l][m] = 0;
                    }
                sum = 0;
 
                swit[1][1] = i;
                swit[1][2] = j;
                swit[1][3] = k;
                changeswit(1,1,i);
                changeswit(1,2,j);
                changeswit(1,3,k);
 
                if(state[1][1] != 0)
                {
                    swit[2][1] = 4 - state[1][1];
                    changeswit(2,1,4 - state[1][1]);
                }
                if(state[1][3] != 0)
                {
                    swit[2][3] = 4 - state[1][3];
                    changeswit(2,3,4 - state[1][3]);
                }
                if(state[1][2] != 0)
                {
                    swit[2][2] = 4 - state[1][2];
                    changeswit(2,2,4 - state[1][2]);
                }
                if(state[2][1] != 0)
                {
                    swit[3][1] = 4 - state[2][1];
                    changeswit(3,1,4 - state[2][1]);
                }
                if(state[2][3] != 0)
                {
                    swit[3][3] = 4 - state[2][3];
                    changeswit(3,3,4 - state[2][3]);
                }
                if(state[2][2] != 0) continue;
                if(state[3][1] == state[3][2] && state[3][1] == state[3][3])
                {
                    swit[3][2] = (4 - state[3][1]) % 4;
                    for(int l = 1; l < 4; l++)
                        for(int m = 1; m < 4; m++)
                            sum += swit[l][m];
                    if(sum < mi)
                    {
                        mi = sum;
                        for(int l = 1; l < 4; l++)
                            for(int m = 1; m < 4; m++)
                                cop[l][m] = swit[l][m];
                    }
                }
                else continue;
            }
        }
    }
    bool f = 0;
    for(int i = 1; i < 4; i++)
        for(int j = 1; j < 4; j++)
        {
            while(cop[i][j]--)
            {
                if(f) printf(" ");
                printf("%d", 3*(i - 1) + j);
                f = 1;
            }
        }
    printf("\n");
    return 0;
}