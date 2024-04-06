#include <bits/stdc++.h>

using namespace std;

struct MAL {
	int x;
	int y;
	int dir;
};
const int dy[] = { 0,0,-1,1 };
const int dx[] = { 1,-1,0,0 };
int N, K,x,y,dir,result = -1;
int a[14][14];
string m[14][14];
vector<MAL> mal;

bool check()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (m[i][j].size() >= 4)
			{
				return true;
			}
		}
	}
	return false;
}
int main()
{
	cin >> N >> K;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> a[i][j];
		}
	}
	for (int i = 0; i < K; i++)
	{
		cin >> y >> x >> dir;
		x--;
		y--;
		m[y][x] += i + '0';
		mal.push_back({x,y,dir - 1});
	}
	for (int T = 1; T <= 1000; T++)
	{
		for (int i = 0; i < mal.size(); i++)
		{
			auto itr = m[mal[i].y][mal[i].x].find(i + '0');
			string movingT = m[mal[i].y][mal[i].x].substr(itr);
			string temp = m[mal[i].y][mal[i].x].substr(0,itr);
			int ny = mal[i].y + dy[mal[i].dir];
			int nx = mal[i].x + dx[mal[i].dir];

			if (ny < 0 || ny >= N || nx < 0 || nx >= N || a[ny][nx] == 2)
			{
				mal[i].dir ^= 1;
				int ny = mal[i].y + dy[mal[i].dir];
				int nx = mal[i].x + dx[mal[i].dir];
				if (ny < 0 || ny >= N || nx < 0 || nx >= N || a[ny][nx] == 2)
				{
					continue;
				}
				else
				{
					i--;
					continue;
				}
			}
			if (a[ny][nx] == 1)
			{
				reverse(movingT.begin(), movingT.end());
			}
			m[ny][nx] += movingT;
			m[mal[i].y][mal[i].x] = temp;
			for (int j = 0; j < movingT.size(); j++)
			{
				int now = movingT[j] - '0';
				mal[now].y = ny;
				mal[now].x = nx;
			}
			if (check())
			{
				cout << T;
				return 0;
			}
		}
	}
	cout << -1;

}