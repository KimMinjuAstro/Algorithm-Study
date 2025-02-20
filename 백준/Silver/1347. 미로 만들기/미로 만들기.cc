#include<iostream>
#include<algorithm>
using namespace std;
int ydir[] = { -1,0,1,0 };
int xdir[] = { 0,1,0,-1 };
string go;
char map[101][101];
int n;
int minY = 101;
int maxY = 0;
int minX=101;
int maxX=0;

void Move() {
	int dirIdx = 2;
	int y = 50, x = 50;
	for (int i = 0; i < go.size(); i++)
	{
		if (go[i] == 'L') {
			dirIdx -= 1;
			if (dirIdx < 0)dirIdx = 3;
		}else if (go[i] == 'R') {
			dirIdx += 1;
			if (dirIdx >3)dirIdx = 0;
		}
		else {
			map[y][x] = '.';
			minY = min(minY, y);
			maxY = max(maxY, y);
			maxX = max(maxX, x);
			minX = min(minX, x);
			y += ydir[dirIdx];
			x += xdir[dirIdx];
			minY = min(minY, y);
			maxY = max(maxY, y);
			maxX = max(maxX, x);
			minX = min(minX, x);
		}
	}
	map[y][x] = '.';
	minY = min(minY, y);
	maxY = max(maxY, y);
	maxX = max(maxX, x);
	minX = min(minX, x);
}

int main() {
	cin >> n;

	cin >> go;

	for (int i = 0; i < 101; i++)
	{
		for (int j = 0; j < 101; j++)
		{
			map[i][j] = '_';	// '_'는 범위 밖
		}
	}
	Move();
	for (int i = minY; i <= maxY; i++)
	{
		for (int j = minX; j <= maxX; j++)
		{
			if(map[i][j]=='_')
				cout << "#";
			else 
				cout << map[i][j];
		}cout << "\n";
	}
}