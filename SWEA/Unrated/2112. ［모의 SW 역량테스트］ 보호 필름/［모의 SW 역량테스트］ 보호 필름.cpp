#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int T;
int D, W, K;
int film[15][25];
vector<int>path;
int cnt;
int ans=21e8;

void init() {
	cnt = 0;
	ans = 21e8;
	path.clear();
	for (int i = 0; i < 15; i++)
	{
		for (int j = 0; j < 25; j++)
		{
			film[i][j] = 0;
		}
	}
}

void input() {
	cin >> D >> W >> K;
	for (int row = 0; row < D; row++)
	{
		for (int col = 0; col < W; col++)
		{
			cin >> film[row][col];
		}
	}
}

bool isValid() {

	// 세로 선 하나 정해서
	for (int col = 0; col < W; col++)
	{
		int prev = film[0][col];	// 맨 윗줄의 특성 확인

		int conti = 1; // 연속 개수

		int countMax = 1;	// 연속 개수 최댓값

		if (path[0] != -1) prev = path[0];	// 약품 투입이 기록되어 있는 대로 맨 윗줄 처리
													

		for (int row = 1; row < D; row++)	// 각 row마다 최대 연속 개수를 계산
		{
			int nowValue = film[row][col];	// 현재 확인할 셀. 기본적으로 원래 셀 정보 가져오기
			if (path[row] != -1) nowValue = path[row];	// 약품이 투입된 경우면 업데이트
			if (prev == nowValue) conti += 1;				// 전의 약품과 똑같다면 연속+1
			else conti = 1;										// 똑같지 않다면 연속 끊기
			prev = nowValue;										// 그 다음줄로 넘어가기. 그래야 다음 for문 때 비교 가능
			countMax = max(countMax, conti);	// 최대로 얼만큼 연속됐는지 확인
		}
		if (countMax < K) return false;
	}
	return true;
}

void func(int now) {
	if (now >= D) {
		if (isValid()) {
			ans = min(ans, cnt);	// 최소 약품 개수 업데이트
		}
		return;
	}

	for (int i = -1; i <=1; i++)
	{
		// i != -1 : 약품 이제 하나 더 넣을건데
		if (i != -1 && cnt + 1 > K)continue;	// 약품 투입했을 시 K개가 넘으면 패스
		if (i != -1 && cnt + 1 > ans)continue;	// 이미 구한 정답보다 더 큰 경우면 패스

		if (i != -1) cnt += 1;
		path.push_back(i);

		func(now + 1);

		if (i != -1)cnt -= 1;
		path.pop_back();
	}
}

void solution() {
	func(0);
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
	return 0;
}