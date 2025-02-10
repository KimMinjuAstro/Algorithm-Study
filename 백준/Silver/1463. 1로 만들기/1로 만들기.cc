#include<iostream>
using namespace std;

int DP[1000000] = {0};

int ToOne(int n){
	if (n <= 1)return 0;
	DP[1] = 0;
	DP[2] = 1;
	DP[3] = 1;
	
	if (DP[n] == 0) { 
		DP[n] = ToOne(n-1) + 1;
		if (n % 3 == 0) {
			DP[n] = min(ToOne(n),ToOne(n / 3) + 1);
		}
		if (n % 2 == 0) {
			DP[n] = min(ToOne(n), ToOne(n / 2) + 1);
		}
	}
	return DP[n];
}
int main() {
	int n;
	cin >> n;
	cout << ToOne(n);
}