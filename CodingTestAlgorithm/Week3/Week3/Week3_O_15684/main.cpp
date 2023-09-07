#include <bits/stdc++.h>

using namespace std;
int N, M, H;
int visited[34][34];
int result = 1000000;

bool check()
{
	for (int i = 1; i < N; i++)
	{
		int start{i};
		for (int j = 1; j <= H; j++)
		{
			if (visited[j][start])
			{
				start++;
			}
			else if(visited[j][start - 1])
			{
				start--;
			}
		}
		if (start != i)
		{
			return false;
		}
	}
	return true;
}

void Func(int here, int count)
{
	if (count > 3 || count >= result)
	{
		return;
	}
	if (check())
	{
		result = min(result, count);
		return;
	}

	for (int i = here; i <= H; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			if (visited[i][j] || visited[i][j + 1] || visited[i][j - 1])
			{
				continue;
			}
			visited[i][j] = 1;
			Func(i, count + 1);
			visited[i][j] = 0;
		}
	}
}

int main()
{
	cin >> N >> M >> H;
	for (int i = 0; i < M; i++)
	{
		int a{}, b{};
		cin >> a >> b;
		visited[a][b] = 1;
	}
	Func(1, 0);
	if (result == 1000000)
	{
		cout << -1;
	}
	else
	{
		cout << result;
	}

}