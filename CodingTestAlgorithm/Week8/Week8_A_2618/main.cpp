#include <bits/stdc++.h>

using namespace std;

int N, W;
int x, y;
int px[1003], py[1003], dp[1003][1003];

int dist(int a, int b)
{
	return abs(px[a] - px[b]) + abs(py[a] - py[b]);
}

int Func(int a, int b)
{
	if (a == W + 1 || b == W + 1)
	{
		return 0;
	}

	if (dp[a][b])
	{
		return dp[a][b];
	}

	int next = max(a, b) + 1;

	return dp[a][b] = min(Func(a, next) + dist(b, next), Func(next, b) + dist(a, next));
}

void Prev()
{
	int a = 0; 
	int b = 1;
	for (int i = 2; i < W + 2; i++)
	{
		if (dp[i][b] + dist(a, i) < dp[a][i] + dist(b, i))
		{
			cout << '1' << '\n';
			a = i;
		}
		else
		{
			cout << '2' << '\n';
			b = i;
		}
	}
}

int main()
{
	cin >> N >> W;
	px[0] = 1;
	py[0] = 1;
	px[1] = N;
	py[1] = N;
	for (int i = 2; i < W + 2; i++)
	{
		cin >> x >> y;
		px[i] = x;
		py[i] = y;
	}
	cout << Func(0, 1)<<'\n';
	Prev();
}
