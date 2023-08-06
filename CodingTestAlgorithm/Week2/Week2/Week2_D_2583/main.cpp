#include <bits/stdc++.h>

using namespace std;


int M, N, K;
bool a[101][101];
bool visited[101][101];
const int dy[] = { -1, 0, 1, 0 };
const int dx[] = { 0 , 1 , 0 , -1 };

int dfs(int y, int x, int num)
{
	visited[y][x] = 1;
	num++;
	for (int i = 0; i < 4; i++)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (ny < 0 || ny >= M || nx < 0 || nx >= N)
		{
			continue;
		}
		if (!visited[ny][nx] && a[ny][nx] == 0)
		{
			num = dfs(ny, nx,num);
		}
	}
	return num;
}
int main()
{
	cin >> M >> N >> K;
	vector<int> result;
	for (int i = 0; i < K; i++)
	{
		int LDX{}, LDY{}, RTX{}, RTY{};
		cin >> LDX >> LDY >> RTX >> RTY;


		for (int j = LDY; j < RTY; j++)
		{
			for (int k = LDX; k < RTX; k++)
			{
				a[j][k] = 1;
			}
		}
	}
	for (int i = 0; i < M; i++)
	{
		for(int j = 0 ; j<N;j++)
		{
			int num{};
			if (!visited[i][j] && a[i][j] == 0)
			{
				num = dfs(i, j, num);
				result.push_back(num);
			}
		}
	}
	
	cout << result.size() << '\n';
	sort(result.begin(), result.end());
	for (auto e : result)
	{
		cout << e << " ";
	}
}