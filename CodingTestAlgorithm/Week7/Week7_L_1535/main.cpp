#include <bits/stdc++.h>

using namespace std;

int N;
int a[21], b[21];
int dp[104];

int Func(int nowH, int nowG,int here)
{
	if (nowH <= 0)
	{
		return 0;
	}
	if (here >= N)
	{
		return nowG;
	}	
	return max(Func(nowH, nowG, here + 1), Func(nowH - a[here], nowG + b[here], here + 1));
}
int main()
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> a[i];
	}
	for (int i = 0; i < N; i++)
	{
		cin >> b[i];
	}
	cout << Func(100, 0, 0);
}