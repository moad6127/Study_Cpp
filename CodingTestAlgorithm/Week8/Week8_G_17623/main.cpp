#include <bits/stdc++.h>

using namespace std;

int T, N;
map<char, char> mp{{'1', '('}, { '2',')' }, { '3','{' }, { '4','}' }, { '5','[' }, { '6',']' }};
string dp[1004];

bool Check(string a, string b)
{
	if (a == "" && b == "")
	{
		return false;
	}
	if (a == "")
	{
		return true;
	}
	if (a.size() == b.size())
	{
		return a > b;
	}
	return a.size() > b.size();
}
int main()
{
	dp[1] = "12";
	dp[2] = "34";
	dp[3] = "56";
	for (int here = 1; here <= 1000; here++)
	{
		// 괄호 안에 넣기
		if (here % 2 == 0 && Check(dp[here], '1' + dp[here / 2] + '2'))
		{
			dp[here] = '1' + dp[here / 2] + '2';
		}
		if (here % 3 == 0 && Check(dp[here], '3' + dp[here / 3] + '4'))
		{
			dp[here] = '3' + dp[here / 3] + '4';
		}
		if (here % 5 == 0 && Check(dp[here], '5' + dp[here / 5] + '6'))
		{
			dp[here] = '5' + dp[here / 5] + '6';
		}
		// 괄호를 뒤로 붙이기
		for (int i = 1; i <= here; i++)
		{
			if (Check(dp[here], dp[i] + dp[here - i]))
			{
				dp[here] = dp[i] + dp[here - i];
			}
		}
	}
	cin >> T;
	for (int t = 0; t < T; t++)
	{
		cin >> N;
		for (auto e : dp[N])
		{
			cout << mp[e];
		}
		cout << '\n';
	}
}