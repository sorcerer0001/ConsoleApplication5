/*
POJ 算法基础 编程题＃1： 完美覆盖

设计思路，棋盘是二维数组。利用二进制来处理
[
[0,0,0,1,1,1,1]
[1,1,1,0,0,0,0]
[0,1,1,1,1,1,1]
[1,1,1,1,1,0,0]
[0,0,0,1,1,1,1]
[1,1,1,1,1,1,1]
]
从网上找到的资料来看这种方法相对容易理解
0，是否能实现完美覆盖参看网上资料,默认满足条件
1，横向的牌为[1,1]
2，纵向的牌为[
            [0],
            [1]
            ]
    纵向牌在棋盘中竖着看，0位起点1位终点
3，完美覆盖的棋牌的最后一排全部必为二进制位的1
4，如果某一位为0，则0下方的必然是1
5，模拟递归，从左上角开始逐行逐位压栈，最后栈顶在倒数第二行最右（最后一行必为1，所以直接在倒数第二行）。
6，初始化棋盘为-1，最后一行为1，坐标[x,y]
    bit(int q){
    return bit(0)+bit(1)//0为竖向方案，1为横向方案
    bit0需要,将[x,y]置为0，将[x-1,y]置为1，bit1将[x,y]置为1，将[x,y-1]置为1
    遇到[x,y]!=-1时跳过[x,y],继续[x,y-1]
7，填充至[0,0],就是一个方案完成，total++;
}
*/
//以下代码非上述攻略的实现（我就压根没看），以下代码为AC码
#include <iostream>
using namespace std;

int horizontal(int n);
int vertical(int n);

int count(int n) {
    if (n == 0) return 1;
    if(n % 2) return 0;
    return horizontal(n)+vertical(n);
}

int horizontal(int n) {
    if (n == 0) return 1;
    if (n == 1) return 0;
    return 2 * vertical(n-1) + horizontal(n-2);
}

int vertical(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    return horizontal(n-1) + vertical(n-2);
}

int main()
{
    int n;
    cin >> n;
    while (n != -1) {
        cout<<count(n);
        cin>>n;
        if (n != -1) cout<<endl;
    }
    return 0;
}