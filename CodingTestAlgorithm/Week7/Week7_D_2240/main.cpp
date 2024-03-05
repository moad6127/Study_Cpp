#include <bits/stdc++.h>

using namespace std;

int T, W;
int dp[1004][2][34];
int a[1004];

int Func(int idx, int tree, int cnt)
{
	if (cnt < 0)
	{
		return -987654321;
	}
	if (idx == T)
	{
		return 0;
	}
	if (dp[idx][tree][cnt] != -1)
	{
		return dp[idx][tree][cnt];
	}
	return dp[idx][tree][cnt] = max(Func(idx + 1, tree ^ 1, cnt - 1), Func(idx + 1, tree, cnt)) + (tree == a[idx] - 1);
}

int main()
{
	memset(dp, -1, sizeof(dp));
	cin >> T >> W;
	for (int i = 0; i < T; i++)
	{
		cin >> a[i];
	}
	cout << max(Func(0, 1, W - 1), Func(0, 0, W));
}