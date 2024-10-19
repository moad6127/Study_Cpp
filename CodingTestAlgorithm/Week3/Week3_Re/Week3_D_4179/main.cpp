#include <bits/stdc++.h>

using namespace std;

int r, c;
string a[1001];
int JY = -1, JX = -1;
const int dy[] = { -1,0,1,0 };
const int dx[] = { 0,-1,0,1 };
vector<pair<int, int>> Fire;
int visitedJ[1001][1001];
int visitedF[1001][1001];
int result{ 987654321 };
void bfsJ()
{	
	queue<pair<int, int>> qJ;
	qJ.push({ JY,JX });
	visitedJ[JY][JX] = 0;
	while (qJ.size())
	{
		pair<int, int> now = qJ.front();
		qJ.pop();
		for (int i = 0; i < 4; i++)
		{
			int ny = now.first + dy[i];
			int nx = now.second + dx[i];
			if (ny < 0 || ny >= r || nx < 0 || nx >= c)
			{
				continue;
			}
			if (a[ny][nx] == '#')
			{
				continue;
			}
			if (a[ny][nx] == 'F')
			{
				continue;
			}
			if (visitedJ[ny][nx] != 987654321)
			{
				continue;
			}
			if (visitedF[ny][nx] <= visitedJ[now.first][now.second] + 1)
			{
				continue;
			}
			visitedJ[ny][nx] = visitedJ[now.first][now.second] + 1;
			qJ.push({ ny,nx });
		}
		
	}
}
void bfsF()
{
	queue<pair<int, int>> q;
	for (auto e : Fire)
	{
		q.push(e);
		visitedF[e.first][e.second] = 0;
	}
	while (q.size())
	{
		pair<int, int> nowF = q.front();
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int ny = nowF.first + dy[i];
			int nx = nowF.second + dx[i];
			if (ny < 0 || ny >= r || nx < 0 || nx >= c)
			{
				continue;
			}
			if (a[ny][nx] == '#')
			{
				continue;
			}
			if (visitedF[ny][nx] != 987654321)
			{
				continue;
			}
			q.push({ ny,nx });
			visitedF[ny][nx] = visitedF[nowF.first][nowF.second] + 1;
		}
	}
}
int main()
{
	cin >> r >> c;
	for (int i = 0; i < r; i++)
	{
		cin >> a[i];
		for (int j = 0; j < c; j++)
		{
			if (a[i][j] == 'J')
			{
				JY = i;
				JX = j;
			}
			if (a[i][j] == 'F')
			{
				Fire.push_back({ i,j });
			}
		}
	}
	fill(&visitedF[0][0], &visitedF[0][0] + 1001 * 1001, 987654321);
	fill(&visitedJ[0][0], &visitedJ[0][0] + 1001 * 1001, 987654321);
	bfsF();
	bfsJ();

	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			if (i == 0 || j ==0 || i ==r - 1|| j == c- 1)
			{
				if (visitedJ[i][j] != -1)
				{
					result = min(result, visitedJ[i][j]);
				}
			}
		}
	}
	if (result == 987654321)
	{
		cout << "IMPOSSIBLE";
	}
	else
	{
		cout << result + 1;
	}

}