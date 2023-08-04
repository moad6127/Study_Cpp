#include <bits/stdc++.h>


using namespace std;

const int dy[] = { -1, 0, 1, 0 };
const int dx[] = { 0 , 1, 0, -1};
int main()
{
	int N{}, M{};
	cin >> N >> M;
	vector<vector<int>> map(N, vector<int>(M, 0));
	vector<vector<int>> visit(N, vector<int>(M, 0));
	for (int i = 0; i < N; i++)
	{
		string list{};
		cin >> list;
		for (int j = 0; j < M; j++)
		{
			map[i][j] =list[j] - '0';
		}
	}
	int sy{}, sx{}, ey{ N - 1 }, ex{ M - 1 };
	queue<pair<int, int>> q;
	visit[sy][sx] = 1;
	q.push({sy,sx});

	while (q.size())
	{
		pair<int, int> temp = q.front();
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int ny = temp.first + dy[i];
			int nx = temp.second + dx[i];

			if (ny < 0 || ny >= N || nx < 0 || nx >= M)
			{
				continue;
			}
			if (!visit[ny][nx] && map[ny][nx])
			{
				visit[ny][nx] = visit[temp.first][temp.second] + 1;
				q.push({ ny,nx });
			}
		}

	}
	cout << visit[ey][ex];
}