#include<iostream>
#include<cstdio>
using namespace std;
int const MAX_STEP = 10000;

int result[20];
int cases;
int n;
int nowRound;

int puzzle[17][17], press[17][17];


bool guess(){

	for (int r = 1; r < n; r++)
		for (int c = 1; c < n + 1; c++){
			press[r + 1][c] = (puzzle[r][c] +
				press[r][c] + press[r - 1][c] + press[r][c - 1] + press[r][c + 1])
				% 2;
		}


	for (int c = 1; c < n + 1; c++){
		if ((press[n][c - 1] + press[n][c] + press[n][c + 1] + press[n - 1][c])
			% 2
			!= puzzle[n][c])
			return false;
	}

	int steps = 0;
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

		while (press[1][c] > 1 && c < n + 1){
			press[1][c] = 0;
			c++;
			press[1][c]++;
		}

		total = 0;
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


