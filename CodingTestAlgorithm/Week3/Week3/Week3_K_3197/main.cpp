#include <bits/stdc++.h>


using namespace std;

int R, C;
vector<string> a;
vector<pair<int, int>> LL;
int visited[1504][1504];
int result;
const int dy[4] = { -1, 1, 0 , 0 };
const int dx[4] = { 0 ,0 ,-1, 1 };


bool BSF()
{
	memset(visited, 0, sizeof(visited));
	queue<pair<int, int>> q;
	q.push(LL[0]);
	visited[LL[0].first][LL[0].second] = 1;
	while (q.size())
	{
		pair<int, int> now = q.front();
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int ny = now.first + dy[i];
			int nx = now.second + dx[i];
			if (ny < 0 || ny >= R || nx < 0 || nx >= C)
			{
				continue;
			}
			if (visited[ny][nx])
			{
				continue;
			}
			if (a[ny][nx] == 'X')
			{
				continue;
			}
			if (ny == LL[1].first && nx == LL[1].second)
			{
				return true;
			}
			visited[ny][nx] = visited[now.first][now.second] + 1;
			q.push({ ny,nx });
		}
	}
	return false;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> R >> C;
	for (int i = 0; i < R; i++)
	{
		string temp;
		cin >> temp;
		a.push_back(temp);
		if (temp.find('L') != string::npos)
		{
			LL.push_back({ i,temp.find('L') });
		}
	}

	while (!BSF())
	{
		vector<pair<int, int>> removeX;
		for (int i = 0; i < R; i++)
		{
			for (int j = 0; j < C; j++)
			{
				if (a[i][j] == 'X')
				{
					for (int k = 0; k < 4; k++)
					{
						int ny = i + dy[k];
						int nx = j + dx[k];
						if (ny < 0 || ny >= R || nx < 0 || nx >= C)
						{
							continue;
						}
						if (a[ny][nx] == '.')
						{
							removeX.push_back({ i,j });
							break;
						}
					}
				}
			}
		}
		for (auto e : removeX)
		{
			a[e.first][e.second] = '.';
		}
		result++;
	}

	cout << result;

	return 0;
}