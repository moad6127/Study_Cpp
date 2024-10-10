#include <bits/stdc++.h>

using namespace std;

const int dy[] = { -1, 0 ,1, 0 };
const int dx[] = { 0,-1,0,1 };

int n, m, a[10][10];
int result;
int bfs()
{
	int visited[10][10];
	memset(visited, 0, sizeof(visited));
	queue<pair<int, int>> q;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if(a[i][j] == 2)
			{
				q.push({ i,j });
				visited[i][j] = 1;
			}
		}
	}
	while (q.size())
	{
		pair<int, int> now = q.front();
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int ny = now.first + dy[i];
			int nx = now.second + dx[i];
			if (ny < 0 || ny >= n || nx < 0 || nx >= m)
			{
				continue;
			}
			if (visited[ny][nx])
			{
				continue;
			}
			if (a[ny][nx])
			{
				continue;
			}
			visited[ny][nx] = 1;
			q.push({ ny,nx });
		}
	}
	int ans{};
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (a[i][j] == 0 && visited[i][j] == 0)
			{
				ans++;
			}
		}
	}
	return ans;
}

void dfs(int blockNum, int y, int x)
{
	if (blockNum == 0)
	{
		result = max(result, bfs());
		
		return;
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (a[i][j] == 0)
			{
				a[i][j] = 1;
				dfs(blockNum - 1,i,j);
				a[i][j] = 0;
			}
		}
	}

}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> a[i][j];
		}
	}
	// 완전 탐색으로 벽을 놓을 3개를 선택한다.
	// 3개의 벽이 선택되면 해당 벽에 대해 안전지대를 생각한다.
	// 최대로 선택된 안전지대를 리턴한다.
	dfs(3,0,0);
	cout << result;
}