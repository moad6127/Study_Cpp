#include <bits/stdc++.h>

using namespace std;


const int dy[] = { -1,0,1,0 };
const int dx[] = { 0,1,0,-1 };
int n,k, l;
int a[101][101], visited[101][101], x, y, dir = 1, num;
char c;
vector<pair<int, int>> v;
int t, check;
deque<pair<int, int>> dq;

int main()
{
	cin >> n >> k;
	for (int i = 0;i < k;i++)
	{
		cin >> y >> x;
		a[--y][--x] = 1;
	}
	cin >> l;
	for (int i = 0; i < l;i++)
	{
		cin >> num >> c;
		if (c == 'D')
		{
			v.push_back({ num,1 });
		}
		else
		{
			v.push_back({ num,3 });
		}
	}
	dq.push_back({ 0,0 });
	while (dq.size())
	{
		t++;
		y = dq.front().first;
		x = dq.front().second;
		int ny = y + dy[dir];
		int nx = x + dx[dir];
		if (ny >= n || ny < 0 || nx >= n || nx < 0 || visited[ny][nx])
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
		if (check <v.size() && t == v[check].first)
		{
			dir = (dir + v[check].second) % 4;
			check++;
		}
	}

	cout << t;
}