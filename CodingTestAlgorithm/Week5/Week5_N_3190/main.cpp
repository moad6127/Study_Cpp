#include <bits/stdc++.h>

using namespace std;

int N,K,L;

int a[101][101],visited[101][101],t;
int dir{ 1 },idx;
int X;
char C;
vector<pair<int, int>> v;
deque<pair<int, int>> dq;
const int dy[] = { -1,0,1,0 };
const int dx[] = { 0, 1,0,-1 };
int y, x;
int main()
{
	cin >> N >> K;
	for (int i = 0; i < K; i++)
	{
		cin >> y >> x;
		a[--y][--x] = 1;
	}
	cin >> L;
	for (int i = 0; i < L; i++)
	{
		cin >> X >> C;
		if (C == 'D')
		{
			v.push_back({ X,1 });
		}
		else
		{
			v.push_back({ X,3 });
		}
	}
	dq.push_back({ 0,0 });

	while (dq.size())
	{
		t++;
		pair<int, int> now = dq.front();
		int ny = now.first + dy[dir];
		int nx = now.second + dx[dir];

		if (ny >= N || ny < 0 || nx >= N || nx < 0 || visited[ny][nx])
		{
			break;
		}

		if (!a[ny][nx])
		{
			visited[dq.back().first][dq.back().second] = 0;
			dq.pop_back();
		}
		else
		{
			a[ny][nx] = 0;
		}
		visited[ny][nx] = 1;
		dq.push_front({ ny,nx });
		if (idx < v.size() && t == v[idx].first)
		{
			dir = (dir + v[idx].second) % 4;
			idx++;
		}
	}
	cout << t;
}