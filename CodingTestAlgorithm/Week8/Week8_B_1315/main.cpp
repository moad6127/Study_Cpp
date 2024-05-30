#include <bits/stdc++.h>

using namespace std;
struct st
{
	int st;
	int in;
	int pt;
};
int N,str,in,pt;
vector<st> v;
int dp[1004][1004];
int Func(int nowSTR, int nowINT, int nowPT, vector<int> clearQ, int count)
{
	int cnt{};

	for (int i = 0 ; i<v.size();i++)
	{
		if (clearQ[i])
		{
			cnt++;
			continue;
		}
		if (nowSTR >= v[i].st || nowINT >= v[i].in)
		{
			nowPT += v[i].pt;
			clearQ[i] = 1;
			cnt++;
		}
	}
	if (cnt < count)
	{
		return 0;
	}
	if (cnt == count || cnt == clearQ.size())
	{
		return cnt;
	}
	if (dp[nowSTR][nowINT])
	{
		return dp[nowSTR][nowINT];
	}
	for (int i = 0; i <= nowPT; i++)
	{
		dp[nowSTR][nowINT] = max(dp[nowSTR][nowINT], Func(nowSTR + i, nowINT + nowPT - i, 0, clearQ,cnt));
	}
	return dp[nowSTR][nowINT];
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;
	vector<int> clear(N, 0);
	for (int i = 0;i < N; i++)
	{
		st s;
		cin >> s.st >> s.in >> s.pt;
		v.push_back(s);
	}
	cout<<Func(1, 1, 0, clear, 0);
}