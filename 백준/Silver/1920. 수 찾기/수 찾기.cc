#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int N, M;
vector<int>n;

bool exist(int num) {
	int low = 0, high = n.size() - 1;

	while (low <= high) {
		int mid = (low + high) / 2;

		if (num == n[mid])return true;

		if (num < n[mid])high = mid - 1;
		else if (num > n[mid])low = mid + 1;
	}

	return false;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int num; cin >> num;
		n.push_back(num);
	}
	sort(n.begin(), n.end());

	cin >> M;
	for (int i = 0; i < M; i++)
	{
		int num; cin >> num;
		if (exist(num))cout << "1\n";
		else cout << "0\n";
	}
}