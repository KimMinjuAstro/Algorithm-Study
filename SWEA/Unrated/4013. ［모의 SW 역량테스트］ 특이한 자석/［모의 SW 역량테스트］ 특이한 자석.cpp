#include<iostream>
#include<cmath>
using namespace std;
int K;
int magnet[4][8] = {};	// 자석 4개의 8개 극 정보
int turn[21][2] = {};		// K개의 회전 정보 turn[K][2]
int answer;

// 1 : 시계, -1, 반시계

void clockWise(int magNum) {
	int newArr[8] = {};
	for (int i = 1; i < 8; i++)
	{
		newArr[i] = magnet[magNum][i - 1];
	}
	newArr[0] = magnet[magNum][7];
	for (int i = 0; i < 8; i++)
	{
		magnet[magNum][i] = newArr[i];
	}
}

void AntiClockWise(int magNum) {
	int newArr[8] = {};
	for (int i = 1; i < 8; i++)
	{
		newArr[i - 1] = magnet[magNum][i];
	}
	newArr[7] = magnet[magNum][0];
	for (int i = 0; i < 8; i++)
	{
		magnet[magNum][i] = newArr[i];
	}
}

// magN : 몇 번째 톱니바퀴, dir : 방향
void Turn(int magN, int dir) {
	int turns[4] = { 0 };
	if (magN == 0) {
		turns[0] = dir;

		if (magnet[0][2] != magnet[1][6]) {
			turns[1] = dir * -1;
			if (magnet[1][2] != magnet[2][6]) {
				turns[2] = turns[1] * -1;
				if (magnet[2][2] != magnet[3][6]) {
					turns[3] = turns[2] * -1;
				}
			}
		}

	}
	else if (magN == 1) {
		turns[1] = dir;

		if (magnet[0][2] != magnet[1][6]) {
			turns[0] = dir * -1;
		}
		if (magnet[1][2] != magnet[2][6]) {
			turns[2] = dir * -1;
			if (magnet[2][2] != magnet[3][6]) {
				turns[3] = turns[2] * -1;
			}
		}

	}
	else if (magN == 2) {
		turns[2] = dir;

		if (magnet[1][2] != magnet[2][6]) {
			turns[1] = dir * -1;
			if (magnet[0][2] != magnet[1][6]) {
				turns[0] = turns[1] * -1;
			}
		}
		if (magnet[2][2] != magnet[3][6]) {
			turns[3] = dir * -1;
		}

	}
	else if (magN == 3) {
		turns[3] = dir;

		if (magnet[2][2] != magnet[3][6]) {
			turns[2] = dir * -1;
			if (magnet[1][2] != magnet[2][6]) {
				turns[1] = turns[2] * -1;
				if (magnet[0][2] != magnet[1][6]) {
					turns[0] = turns[1] * -1;
				}
			}
		}

	}

	for (int i = 0; i < 4; i++)
	{
		if (turns[i] == 1) {
			clockWise(i);
		}
		else if (turns[i] == -1)
		{
			AntiClockWise(i);
		}
	}
}

void init() {

}
void input() {
	cin >> K;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			cin >> magnet[i][j];
		}
	}
	for (int i = 0; i < K; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			cin >> turn[i][j];
		}
	}
}
void solution() {
	for (int i = 0; i < K; i++)
	{
		Turn(turn[i][0] - 1, turn[i][1]);
	}

	//for (int j = 0; j < 4; j++)
	//{
	//	for (int i = 0; i < 8; i++)
	//	{
	//		cout << magnet[j][i] << " ";
	//	}cout << "\n";
	//}

	int sum = 0;
	for (int i = 0; i < 4; i++)
	{
		sum += magnet[i][0] * pow(2, i);
	}
	answer = sum;
}

int main() {
	int TC;
	cin >> TC;
	for (int i = 1; i <= TC; i++)
	{
		init();
		input();
		solution();
		cout << "#" << i << " " << answer << "\n";
	}

}