#include<iostream>
using namespace std;

int n;
int TC;

int Run(int n) {
	if (n == 0) {
		return 1;
	}

	if (n < 0) {
		return 0;
	}

	return Run(n - 1) + Run(n - 2) + Run(n - 3);
}

int main() {
	cin >> TC;
	for (int i = 0; i < TC; i++)
	{
		n = 0;
		cin >> n;
		cout << Run(n) << "\n";
	}
}