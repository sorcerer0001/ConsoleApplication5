//1.录入数据
//2.初始化puzzle,press
//3.guess用于验证当前方案是否可以执行，3-1通过第一行计算所有的press值，3-2验证最后一行是否全部关闭
//4.上述方案不通过的情况下，对第一行进行累加（模拟二进制进位），每累加一次计算一次press值，然后验证是否通过
//5.通过的情况下，计算press中的1（即为按下的次数）


#include<iostream>
#include<cstdio>
using namespace std;
int const MAX_STEP = 10000;

int result[20];//存放每次cases的结果
int cases;
int n;//矩阵大小
int nowRound;//对应cases中的第nowRound次（nowRound/cases）

int puzzle[17][17], press[17][17];


bool guess(){
	//根据press第一行和puzzle数组，计算其他press行
	for (int r = 1; r < n; r++)
		for (int c = 1; c < n + 1; c++){
			press[r + 1][c] = (puzzle[r][c] +
				press[r][c] + press[r - 1][c] + press[r][c - 1] + press[r][c + 1])
				% 2;
		}

	//判断所计算的press数组能否熄灭最后一行所有的灯
	for (int c = 1; c < n + 1; c++){
		if ((press[n][c - 1] + press[n][c] + press[n][c + 1] + press[n - 1][c])
			% 2
			!= puzzle[n][c])
			return false;
	}

	int steps = 0;//计算总步数
	for (int r = 1; r < n + 1; r++)
		for (int c = 1; c < n + 1; c++){
			if (press[r][c] == 1)
				steps++;
		}

	if (steps<result[nowRound])
		result[nowRound] = steps;
	return true;
}


void enumerate(){
	//bool success;
	for (int j = 0; j < n + 2; j++){
		press[1][j] = 0;
	}

	int total = 0;
	int c = 0;


	guess();
	do
	{
		press[1][1]++;
		c = 1;
		//模拟二进制累加
		while (press[1][c] > 1 && c < n + 1){
			press[1][c] = 0;
			c++;
			press[1][c]++;
		}

		total = 0;//用于验证第一行是否枚举所有方案
		for (int j = 1; j < n + 1; j++){
			total += press[1][j];
		}

		guess();
	} while (total < n);


}



int main(){
 	for (int i = 0; i < 20; i++){
		result[i] = MAX_STEP;
	}

	cin >> cases;
	for (int a = 0; a < cases; a++){
		nowRound = a;
		cin >> n;

		//ÖÜÎ§Ò»È¦ÇåÁã
		//for (int c = 0; c < n + 2; c++)
		//	press[0][c] = press[n + 1][c] = 0;
		//for (int r = 0; r < n + 2; r++)
		//	press[r][0] = press[r][n + 1] = 0;

		//Í¨Í¨ÇåÁã
		//for (int r = 0; r < n + 2; r++)
		//	for (int c = 0; c < n + 2; c++)
		//		puzzle[r][c] = press[r][c] = 0;
		memset(puzzle, 0, sizeof(puzzle));
		memset(press  , 0, sizeof(press  ));

		for (int i = 1; i <= n; i++){
			for (int j = 1; j <= n; j++){
				char color;
				cin >> color;
				if (color == 'y')
					puzzle[i][j] = 0;
				else
					puzzle[i][j] = 1;
			}
		}
		enumerate();
	}


	for (int a = 0; a < cases; a++){
		if (result[a] < MAX_STEP)
			cout << result[a] << endl;
		else
			cout << "inf" << endl;
	}

}


