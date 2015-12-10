#include<iostream>
#include <algorithm>
using namespace std;
int N;
long upNums[251][251];

//计算最大数小于max和为N上升数列的组合数
long upNum(int N, int max) {
    long count = 0;
    if (upNums[N][max] != -1) return upNums[N][max]; // 如果储存了，直接return
    if (max == 1 || N == 0) {
        upNums[N][max] = 1;
        return 1;
    }
    if (max < 1) {//最大数不能小于1
        upNums[N][max] = 0;
        return 0;
    }
    if (max > N) {// 如果最大数大于和，那么转化为求upNum(max, max)
        upNums[N][max] = upNum(N,N);
        return upNums[N][N];
    }
    for (int i = 1; i <= max; ++i) {
        count += upNum(N-i, i);
    }
    upNums[N][max] = count;
    return count;
}

//计算和为N的单峰序列组合数
long conbinationNum(int N) {
    bool even = (N + 1) % 2;//判断N是奇数还是偶数
    long count = 0;
    for (int i = 1; i <= N; ++i) {
        int base, numOfI = 1;
        if (even) {
            if ((i % 2)) {
                base = 2; //如果N是偶数,i是奇数，那么中间i的个数只能是偶数个
                numOfI = 2;
            } else { // 如果N是偶数，i是偶数，那么中间i的个数可以数奇数个也可以是偶数个
                base = 1;
            }
            while ((i * numOfI) <= N) {
                count += upNum((N- (i * numOfI))/2, i - 1);
                numOfI += base;
            }
        } else {
            if ((i % 2)) {
                base = 2;//如果N是奇数,i只能是奇数，那么中间i的个数只能是奇数个
                while ((i * numOfI) <= N) {
                    count += upNum((N- (i * numOfI))/2, i - 1);
                    numOfI += base;
                }
            }
        }
    }
    return count;
}

int main()
{
    for (int i = 0; i < 251; ++i) {
        for (int j = 0; j < 251; ++j) {
            upNums[i][j] = -1;
        }
    }
    cin>>N;
    while(N) {
        cout<<N<<" "<<conbinationNum(N)<<endl;
        cin>>N;
    }
    return 0;
}