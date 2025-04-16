#include<iostream>
#include<cstring>
using namespace std;
int n, x;	// n 가로 세로, x 경사로 길이
int ans;
int map[21][21];
int ramp[21][21];
void init() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
}
void input() {
	cin >> n >> x;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> map[i][j];
		}
	}
}
// 가로 체크
bool RowCheck(int row) {
	
	for (int col = 0; col < n - 1; col++)
	{
		int now = map[row][col];
		int next = map[row][col + 1];
		
		if (now == next)continue;
		else if (now > next + 1 || now < next - 1)return false;
		else if (now == next + 1)	// 왼쪽이 하나 더 큼
		{
			for (int cnt = 0; cnt < x; cnt++)
			{
				if (col + cnt >= n)return false;
				if (map[row][col + cnt + 1] != next)return false;
			}
			for (int cnt = 0; cnt < x; cnt++)
			{
				ramp[row][col + cnt + 1] = 1;
			}
		}
		else if (now + 1 == next) {	// 오른쪽이 하나 더 큼
			for (int cnt = 0; cnt < x; cnt++)
			{
				if (col - cnt < 0)return false;
				if (map[row][col - cnt] != now)return false;
				if (ramp[row][col - cnt] > 0)return false;
			}
			for (int cnt = 0; cnt < x; cnt++)
			{
				ramp[row][col - cnt] = 1;
			}
		}
	}
}

// 세로 체크
bool ColCheck(int col) {
	for (int row = 0; row < n - 1; row++)
	{
		int now = map[row][col];
		int next = map[row + 1][col];

		if (now == next)continue;
		else if (now > next + 1 || now < next - 1)return false;
		else if (now == next + 1)	// 위쪽이 하나 더 큼
		{
			for (int cnt = 0; cnt < x; cnt++)
			{
				if (row + cnt >= n)return false;
				if (map[row + cnt + 1][col] != next)return false;
			}
			for (int cnt = 0; cnt < x; cnt++)
			{
				ramp[row + cnt + 1][col] = 1;
			}
		}
		else if (now + 1 == next) {	// 오른쪽이 하나 더 큼
			for (int cnt = 0; cnt < x; cnt++)
			{
				if (row - cnt < 0)return false;
				if (map[row - cnt][col] != now)return false;
				if (ramp[row - cnt][col] > 0)return false;
			}
			for (int cnt = 0; cnt < x; cnt++)
			{
				ramp[row - cnt][col] = 1;
			}
		}
	}
	return true;
}

void solution() {
	int sum = 0;
	for (int i = 0; i < n; i++)
	{
		// 각 행 보기
		if (RowCheck(i)) { 
		sum++; 
		//cout << i << "행 O" << "\n";
		}
		//else {
			//cout << i << "행 X" << "\n";
		//}
	}
	memset(ramp, 0, sizeof(ramp));
	for (int i = 0; i < n; i++)
	{
		// 각 열 보기
		if (ColCheck(i)) {
			sum++;
			//cout << i << "열 O" << "\n";
		}
		//else {
			//cout << i << "열 X" << "\n";
		//}
	}
	memset(ramp, 0, sizeof(ramp));
	ans = sum;
}

int main() {
	int TC;
	cin >> TC;
	for (int i = 1; i <= TC; i++)
	{
		init();
		input();
		solution();
		cout << "#" << i << " " << ans << "\n";
	}
}