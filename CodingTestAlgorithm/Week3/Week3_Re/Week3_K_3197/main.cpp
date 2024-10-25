#include <bits/stdc++.h>

using namespace std;
int r, c,swanX,swanY;
char a[1501][1501];
string s;
int result;
const int dy[] = { -1,0,1,0 };
const int dx[] = { 0,-1,0,1 };
int visited[1501][1501];
int visited_Swan[1501][1501];
queue<pair<int, int>> wQ, w_temp, sQ, s_temp;
pair<int, int> now;
void water()
{
	while (wQ.size())
	{
		now = wQ.front();
		wQ.pop();
		for (int i = 0; i < 4; i++)
		{
			int ny = now.first + dy[i];
			int nx = now.second + dx[i];
			if (ny < 0 || ny >= r || nx < 0 || nx >= c)
			{
				continue;
			}
			if (visited[ny][nx])
			{
				continue;
			}
			if (a[ny][nx] == 'X')
			{
				visited[ny][nx] = 1;
				w_temp.push({ ny,nx });
				a[ny][nx] = '.';
			}
		}
	}
}

bool swan()
{
	while (sQ.size())
	{
		now = sQ.front();
		sQ.pop();
		for (int i = 0; i < 4; i++)
		{
			int ny = now.first + dy[i];
			int nx = now.second + dx[i];
			if (ny < 0 || ny >= r || nx < 0 || nx >= c)
			{
				continue;
			}
			if (visited_Swan[ny][nx])
			{
				continue;
			}
			visited_Swan[ny][nx] = 1;
			if (a[ny][nx] == '.')
			{
				sQ.push({ ny,nx });
			}
			else if (a[ny][nx] == 'X')
			{
				s_temp.push({ ny,nx });
			}
			else if (a[ny][nx] == 'L')
			{
				return true;
			}
		}
	}
	return false;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> r >> c;
	for (int i = 0; i < r; i++)
	{
		cin >> s;
		for (int j = 0; j < c; j++)
		{
			a[i][j] = s[j];
			if (a[i][j] == 'L')
			{
				swanY = i;
				swanX = j;
			}
			if (a[i][j] == '.' || a[i][j] == 'L')
			{
				visited[i][j] = 1;
				wQ.push({ i,j });
			}
		}
	}
	sQ.push({ swanY, swanX });
	visited_Swan[swanY][swanX] = 1;
	while (true)
	{
		if (swan())
		{
			break;
		}
		water();
		sQ = s_temp;
		wQ = w_temp;
		s_temp = queue<pair<int, int>>();
		w_temp = queue<pair<int, int>>();
		result++;

	}
	cout << result;
}