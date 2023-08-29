#include <bits/stdc++.h>

using namespace std;
int N, M, jx1, jy1, chx2, chy2;
vector<string>a;
int visited[304][304];
const int dy[4] = { -1,1,0,0 };
const int dx[4] = { 0 ,0 ,-1, 1 };
int main()
{
	cin >> N >> M >> jy1 >> jx1 >> chy2 >> chx2;
	jx1--;
	jy1--;
	chx2--;
	chy2--;
	for (int i = 0; i < N; i++)
	{
		string temp;
		cin >> temp;
		a.push_back(temp);
	}

	queue<pair<int, int>>q;
	q.push({ jy1,jx1 });
	visited[jy1][jx1] = 1;
	int check{};
	while (a[chy2][chx2] != '0')
	{
		check++;
		queue<pair<int, int>>temp;
		while (q.size())
		{
			pair<int, int> now = q.front();
			q.pop();
			for (int i = 0; i < 4; i++)
			{
				int ny = now.first + dy[i];
				int nx = now.second + dx[i];
				if (ny < 0 || ny >= N || nx < 0 || nx >= M)
				{
					continue;
				}
				if (visited[ny][nx])
				{
					continue;
				}
				visited[ny][nx] = check;
				if (a[ny][nx] != '0')
				{
					a[ny][nx] = '0';
					temp.push({ ny,nx });
				}
				else
				{
					q.push({ ny,nx });
				}
			}
		}
		q = temp;
	}
	cout << visited[chy2][chx2];
}