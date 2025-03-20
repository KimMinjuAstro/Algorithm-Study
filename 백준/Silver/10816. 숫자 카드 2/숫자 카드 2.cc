#include<iostream>
#include<algorithm>
using namespace std;
int N, M;	// N : 숫자 카드의 개수
				// M : 몇 개 가지고 있는지 구해야 할 정수
int numCard[500001];
int tarCard[500001];
void init() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
}
void input() {
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> numCard[i];
	}
	cin >> M;
	for (int i = 0; i < M; i++)
	{
		cin >> tarCard[i];
	}
}
void solution() {
	sort(numCard, numCard + N);

	for (int num = 0; num < M; num++)
	{
		int curNum = tarCard[num];
		int upperBound = upper_bound(numCard, numCard + N, curNum) - numCard;
		int lowerBound = lower_bound(numCard, numCard + N, curNum) - numCard;

		cout << upperBound - lowerBound << " ";
	}
}
int main() {
	init();
	input();
	solution();
}

