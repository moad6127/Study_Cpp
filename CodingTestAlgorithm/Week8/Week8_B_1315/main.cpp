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
bool visited[101];
int Func(int nowSTR, int nowINT)
{
	if (dp[nowSTR][nowINT] != -1)
	{
		return dp[nowSTR][nowINT];
	}
	dp[nowSTR][nowINT] = 0;
	int ptr{};
	vector<int> visit;
	for (int i = 0 ; i<N;i++)
	{
		if (nowSTR >= v[i].st || nowINT >= v[i].in)
		{
			dp[nowSTR][nowINT]++;
			if (!visited[i])
			{
				ptr += v[i].pt;
				visited[i] = true;
				visit.push_back(i);
			}
		}
	}
	for (int i = 0; i <= ptr; i++)
	{
		int nextSTR = min(1000, nowSTR + i);
		int nextINT = min(1000, nowINT + ptr - i);
		dp[nowSTR][nowINT] = max(dp[nowSTR][nowINT], Func(nextSTR, nextINT));
	}

	for (auto e : visit)
	{
		visited[e] = false;
	}

	return dp[nowSTR][nowINT];
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;
	vector<int> clear(N + 1, 0);
	memset(dp, -1, sizeof(dp));
	for (int i = 0;i < N; i++)
	{
		st s;
		cin >> s.st >> s.in >> s.pt;
		v.push_back(s);
	}
	cout<<Func(1, 1);
}