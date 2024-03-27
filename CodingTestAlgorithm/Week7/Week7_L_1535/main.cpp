//#include <bits/stdc++.h>
//
//using namespace std;
//
//int N;
//int a[21], b[21];
//int dp[104][21];
//const int MAX = 987654321;
//int Func(int nowH,int here)
//{
//	if (nowH <= 0)
//	{
//		return -MAX;
//	}
//	if (here >= N)
//	{
//		return 0;
//	}
//	if (dp[nowH][here])
//	{
//		return dp[nowH][here];
//	}
//	dp[nowH][here] = max(Func(nowH, here + 1), Func(nowH - a[here], here + 1) + b[here]);
//	return dp[nowH][here];
//}
//int main()
//{
//	cin >> N;
//	for (int i = 0; i < N; i++)
//	{
//		cin >> a[i];
//	}
//	for (int i = 0; i < N; i++)
//	{
//		cin >> b[i];
//	}
//	cout << Func(100, 0);
//}

#include <bits/stdc++.h>

using namespace std;

int n, dp[101], cost[101], happy[101];
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> cost[i];
	}
	for (int i = 0; i < n; i++)
	{
		cin >> happy[i];
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 100; j > cost[i]; j--)
		{
			dp[j] = max(dp[j], dp[j - cost[i]] + happy[i]);
		}
	}
	cout << dp[100];
}