#include<iostream>
#include<vector>
#include<cstring>
using namespace std;
int H, W;
int N;	// 사용자의 입력 개수
string cmd;
char map[21][21];
int ydir[] = { -1, 0, 1, 0 };	// 상, 우, 하, 좌
int xdir[] = { 0, 1, 0, -1 };

int y, x, dir;

void init() {

}
void input() {
	cin >> H >> W;
	for (int i = 0; i < H; i++)
	{
		for (int j = 0; j < W; j++)
		{
			cin >> map[i][j];
			if (map[i][j] == '^')
				y = i, x = j, dir = 0;
			else if (map[i][j] == '>')
				y = i, x = j, dir = 1;
			else if (map[i][j] == 'v')
				y = i, x = j, dir = 2;
			else if (map[i][j] == '<')
				y = i, x = j, dir = 3;
		}
	}
	cin >> N;
	cin >> cmd;
}

// 해당 방향으로 회전 후 움직임
void move(int d) {
	map[y][x]='.';

	int ny = y + ydir[d];
	int nx = x + xdir[d];

	if (ny < 0 || ny >= H || nx < 0 || nx >= W)return;
	if (map[ny][nx] != '.')return;

	y = ny, x = nx;
}

// 해당 방향으로 포탄 쏘기
void shoot(int d) {
	int t = 0;
	while (++t) {
		int sy = y + ydir[d] * t;
		int sx = x + xdir[d] * t;
		
		if (sy < 0 || sy >= H || sx < 0 || sx >= W)break;
		if (map[sy][sx] == '#')break;
		if (map[sy][sx] == '*') {
			map[sy][sx] = '.';
			break;
		}
	}
}
void simulation() {
	for (int i = 0; i < N; i++)
	{
		char c = cmd[i];

		//cout << c << "\n";
		//for (int i = 0; i < H; i++)
		//{
		//	for (int j = 0; j < W; j++)
		//	{
		//		cout << map[i][j];
		//	}cout << "\n";
		//}
		int de = - 1;

		if (c == 'U') {
			dir = 0;
			move(dir);
			map[y][x] = '^';	// move가 끝난 후 바뀐 y와 x로 방향 갱신
		}
		else if (c == 'R') {
			dir = 1;
			move(dir);
			map[y][x] = '>';
		}
		else if (c == 'D') {
			dir = 2;
			move(dir);
			map[y][x] = 'v';
		}
		else if (c == 'L') {
			dir = 3;
			move(dir);
			map[y][x] = '<';
		}
		else if (c == 'S') {
			shoot(dir);
		}


	}
}

int main() {
	int TC;
	cin >> TC;
	for (int i = 1; i <= TC; i++)
	{
		init();
		input();
		simulation();

		cout << "#" << i << " ";
		for (int i = 0; i < H; i++)
		{
			for (int j = 0; j < W; j++)
			{
				cout << map[i][j] << "";
			}cout << "\n";
		}
	}
}
