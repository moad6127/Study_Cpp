#include <bits/stdc++.h>

using namespace std;

bool Prim[24];
double A, B, dp[24][24][24];

double Func(int idx, int x, int y)
{
	if (idx == 18)
	{
		return Prim[x] || Prim[y] ? 1.0 : 0.0;
	}
	if (dp[idx][x][y] > -0.5)
	{
		return dp[idx][x][y];
	}
	dp[idx][x][y] = 0;
	dp[idx][x][y] += Func(idx + 1, x, y) * (1 - A) * (1 - B);
	dp[idx][x][y] += Func(idx + 1, x + 1, y) * A * (1 - B);
	dp[idx][x][y] += Func(idx + 1, x, y + 1) * (1 - A) * B;
	dp[idx][x][y] += Func(idx + 1, x + 1, y + 1) * A * B;

	return dp[idx][x][y];
}


void PrimChe()
{
	fill(Prim, Prim + 20, 1);
	Prim[0] = 0;
	Prim[1] = 0;
	for (int i = 2; i <= 20; i++)
	{
		for (int j = i + i; j <= 20; j += i)
		{
			Prim[j] = 0;
		}
	}
}
int main()
{
	cin >> A >> B;
	A /= 100;
	B /= 100;
	PrimChe();
	memset(dp, -1, sizeof(dp));

	cout << Func(0, 0, 0);
}