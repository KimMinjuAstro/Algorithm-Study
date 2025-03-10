#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;
int N, K;
int ans;
int hextodec(string s) {

	int dec = 0;
	for (int i = 0; i < s.size(); i++)
	{
		char digit = s[s.size() - i - 1];
		int digitNum = digit >= 'A' ? digit - 'A' + 10 : digit - '0';
		int hex = pow(16, i);
		dec += digitNum * hex;
	}
	return dec;

}
int main() {
	int TC;
	cin >> TC;
	for (int i = 1; i <= TC; i++)
	{
		vector<string>v;
		vector<string>v_parse;

		cin >> N >> K;
		string s;
		cin >> s;
		s += s;

		for (int i = 0; i < N; i++)
		{
			v.push_back(s.substr(i, N / 4));
		}
		
		sort(v.begin(), v.end());

		for (int i = 0; i < v.size(); i++)
		{
			if (i == 0 || v[i] != v[i - 1])
				v_parse.push_back(v[i]);
		}

		ans = hextodec(v_parse[v_parse.size() - K]);
		cout << "#" << i << " " << ans << "\n";
	}
}