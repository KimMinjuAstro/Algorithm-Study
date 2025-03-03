#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
using namespace std;
int N;
int ydir[] = { 1,-1,0,0 };
int xdir[] = { 0,0,-1,1 };
int map[4001][4001];
int ans;

/*
1
4
-1000 0 3 5
1000 0 2 3
0 1000 1 7
0 -1000 0 9

1
4
-1 1 3 3
0 1 1 1
0 0 2 2
-1 0 0 9
*/
struct Atom
{
	int y;
	int x;
	int dir;	// 상 하 좌 우
				// 0  1  2  3
	int energy;
	bool isAlive;
};
vector<Atom>atoms;
void init() {
	memset(map, 0, sizeof(map));
	ans = 0;
	atoms.clear();
}
void input() {
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		Atom atom;
		atom.isAlive = true;
		cin >> atom.x >> atom.y >> atom.dir >> atom.energy;
		atom.x = (atom.x + 1000) * 2;
		atom.y = (atom.y + 1000) * 2;
		atoms.push_back(atom);
		map[atom.y][atom.x] = 1;
	}
}
void solution() {
	// 모든 원자가 소멸할 때까지
	while (1) {
		bool endFlag=true;
		for (int i = 0; i < N; i++)
		{
			// 하나라도 살아있으면 진행해야함
			if (atoms[i].isAlive) {
				endFlag = false;
			}
		}
		if (endFlag)break;

		// 각 원자들 이동
		for (int i = 0; i < N; i++)
		{
			Atom now = atoms[i];
			if (!now.isAlive)continue;
			map[now.y][now.x] = 0;	// 원래 좌표 0 표시
			int ny = now.y + ydir[now.dir];
			int nx = now.x + xdir[now.dir];
			if (ny < 0 || ny > 4000 || nx < 0 || nx > 4000) {
				atoms[i].isAlive = false;
				continue;
			};
			atoms[i].y = ny;
			atoms[i].x = nx;
			map[ny][nx] += 1;
		}

		// 같은 위치에 있을 경우 소멸
		int expEnergy = 0;
		for (int i = 0; i < N; i++)
		{
			Atom now = atoms[i];
			if (map[now.y][now.x] > 1) {
				for (int j = 0; j < N; j++)
				{
					Atom next = atoms[j];
					if (map[next.y][next.x] == map[now.y][now.x] && next.isAlive) {
						//cout << next.y << "," << next.x << " 좌표에서 폭발 : " <<next.energy<<"추가됨"<< "\n";
						atoms[j].isAlive = false;
						expEnergy += next.energy;
					}
				}
				map[now.y][now.x] = 0;
			}
		}

		//for (int i = 0; i < 10; i++)
		//{
		//	for (int j = 0; j < 10; j++)
		//	{
		//		cout << map[i][j] << " ";
		//	}cout << "\n";
		//}cout << "\n";


		ans += expEnergy;
	}
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