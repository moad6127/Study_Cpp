#include <bits/stdc++.h>

using namespace std;

int N, M, K;

int a[51][51], b[51][51] ,visited[51][51];
vector<vector<int>> v;
vector<pair<int, int>> vv;
vector<int> v_idx;
int r, c, s, sy, sx, ey, ex, dir;
int result = 987654321;

const int dy[] = { 0,1,0,-1 };
const int dx[] = { 1,0,-1,0 };

void Go(int y, int x, int first)
{
	if (!first && y == sy && x == sx)
	{
		dir++;
	}
	if (!first && y == sy && x == ex)
	{
		dir++;
	}
	if (!first && y == ey && x == ex)
	{
		dir++;
	}
	if (!first && y == ey && x == sx)
	{
		dir++;
	}

	int ny = y + dy[dir];
	int nx = x + dx[dir];
	if (visited[ny][nx])
	{
		return;
	}
	visited[ny][nx] = 1;
	vv.push_back({ ny,nx });
	Go(ny, nx, 0);
}

void RotateAll(int y, int x, int cnt)
{
	for (int i = 1; i <= cnt; i++)
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
		Go(sy, sx, 1);

		vector<int> vvv;
		for (pair<int, int> c : vv)
		{
			vvv.push_back(b[c.first][c.second]);
		}
		rotate(vvv.rbegin(), vvv.rbegin() + 1, vvv.rend());
		for (int i = 0; i < vv.size(); i++)
		{
			b[vv[i].first][vv[i].second] = vvv[i];
		}
	}
}

int Solve()
{
	for (int e : v_idx)
	{
		RotateAll(v[e][0], v[e][1], v[e][2]);
	}
	int Min = 987654321;
	for (int i = 0; i < N; i++)
	{
		int cnt = 0;
		for (int j = 0; j < M; j++)
		{
			cnt += b[i][j];
		}
		Min = min(Min, cnt);
	}


	return Min;
}
int main()
{
	cin >> N >> M >> K;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> a[i][j];
		}
	}

	for (int i = 0; i < K; i++)
	{
		cin >> r >> c >> s;
		vector<int> temp = { --r,--c,s };
		v.push_back(temp);
		v_idx.push_back(i);
	}
	do
	{
		memcpy(b, a, sizeof(b));
		result = min(result, Solve());

	} while (next_permutation(v_idx.begin(), v_idx.end()));
	cout << result;
}