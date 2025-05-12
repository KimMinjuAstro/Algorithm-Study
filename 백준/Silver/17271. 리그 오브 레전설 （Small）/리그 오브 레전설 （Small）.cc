#include<iostream>
#define mod 1'000'000'007
using namespace std;
int DP[10001];
int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 1; i < m; i++)
	{
		DP[i] = 1;
	}
	DP[m] = 2;
	for (int i = m + 1; i <= n; i++)
	{
		DP[i] = (DP[i - 1] + DP[i - m]) % mod;
	}
	int de = -1;
	cout << DP[n];
}