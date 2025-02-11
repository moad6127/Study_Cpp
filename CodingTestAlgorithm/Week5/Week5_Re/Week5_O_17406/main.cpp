#include<bits/stdc++.h>

using namespace std;

struct Info
{
	int r;
	int c;
	int s;
};
int n, m, k, r, c, s, dir, sy, sx, ey, ex;
int a[104][104], b[104][104], visited[104][104];
int result = 987654321;
const int dy[] = { 0,1,0,-1 };
const int dx[] = { 1,0,-1,0 };
vector<pair<int, int>>vv;
vector<int>v_idx;
vector<Info> v;

void go(int y, int x, int fir)
{
	if (!fir && y == sy && x == sx) dir++;
	if (!fir && y == sy && x == ex) dir++;
	if (!fir && y == ey && x == ex) dir++;
	if (!fir && y == ey && x == sx) dir++;

	int ny = y + dy[dir];
	int nx = x + dx[dir];
	if (visited[ny][nx])
	{
		return;
	}
	visited[ny][nx] = 1;
	vv.push_back({ ny,nx });
	go(ny, nx, 0);
}

void rotateAll(int y, int x, int cnt)
{
	for (int i = 1;i <= cnt;i++)
	{
		sy = y - 1 * i;
		sx = x - 1 * i;
		ey = y + 1 * i;
		ex = x + 1 * i;
		vv.clear();
		dir = 0;
		memset(visited, 0, sizeof(visited));
		visited[sy][sx] = 1;
		vv.push_back({ sy,sx });
		go(sy, sx, 1);
		vector<int> vvv;
		for (pair<int, int> c : vv)
		{
			vvv.push_back(b[c.first][c.second]);
		}
		rotate(vvv.rbegin(), vvv.rbegin() + 1, vvv.rend());
		for (int i = 0;i < vv.size();i++)
		{
			b[vv[i].first][vv[i].second] = vvv[i];
		}
	}
}
int Func()
{
	for (int i : v_idx)
	{
		rotateAll(v[i].r,v[i].c,v[i].s);
	}
	int mn = 987654321;
	for (int i = 0;i < n;i++)
	{
		int cnt = 0;
		for (int j = 0;j < m;j++)
		{
			cnt += b[i][j];
		}
		mn = min(mn, cnt);
	}
	return mn;
}

int main()
{
	cin >> n >> m >> k;
	for (int i = 0;i < n;i++)
	{
		for (int j = 0;j < m;j++)
		{
			cin >> a[i][j];
		}
	}
	for (int i = 0; i < k;i++)
	{
		cin >> r >> c >> s;
		r--;
		c--;
		v.push_back({ r,c,s });
		v_idx.push_back(i);
	}
	do
	{
		memcpy(b, a, sizeof(b));
		result = min(result, Func());
	} while (next_permutation(v_idx.begin(), v_idx.end()));
	cout << result;
}