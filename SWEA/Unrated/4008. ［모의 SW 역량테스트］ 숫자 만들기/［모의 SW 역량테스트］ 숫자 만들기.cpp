#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

int answer;
int N;	// 숫자 개수
int opr[4];	// +, -, *, / 순서대로 몇 개인지 확인. 총 N-1개 opr[N-1]
int nums[12];	// 숫자들. 총 N개 nums[N]
int path[12];	// 0 = +
					// 1 = -
					// 2 = *
					// 3 = /
int maxCal;
int minCal;

void Calculator() {
	int cal = nums[0];
	for (int i = 0; i < N - 1; i++)
	{
		if (path[i] == 0) {
			cal += nums[i + 1];
		}
		else if (path[i] == 1) {
			cal -= nums[i + 1];
		}
		else if (path[i] == 2) {
			cal *= nums[i + 1];
		}
		else if (path[i] == 3) {
			if (nums[i + 1] != 0) {
				cal /= nums[i + 1];

			}
		}
	}
	maxCal = max(maxCal, cal);
	minCal = min(minCal, cal);
}

void run(int now) {
	if (now == N - 1) {
		//for (int i = 0; i < N - 1; i++)
		//{
		//	cout << path[i] << " ";
		//}cout << "\n";
		Calculator();
		return;
	}

	for (int i = 0; i < 4; i++)
	{
		if (opr[i] == 0)continue;
		path[now] = i;
		opr[i]--;

		run(now + 1);

		path[now] = 0;
		opr[i]++;
	}
}

void init() {
	memset(opr, 0, sizeof(opr));
	memset(nums, 0, sizeof(nums));
	memset(path, 0, sizeof(path));
	maxCal = -21e8;
	minCal = 21e8;
}

void input() {
	cin >> N;
	for (int i = 0; i < 4; i++)
	{
		cin >> opr[i];
	}
	for (int i = 0; i < N; i++)
	{
		cin >> nums[i];
	}
}

void solution() {
	run(0);
	answer = maxCal - minCal;
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