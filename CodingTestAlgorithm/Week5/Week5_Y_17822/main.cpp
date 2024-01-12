#include <bits/stdc++.h>

using namespace std;

int N, M, T, a, x, d, k,sum,CCount;
vector<vector<int>>v;

const int dy[] = { 1,0,-1,0 };
const int dx[] = { 0,1,0,-1 };

void Rotation(int x, int dir, int k)
{
	for (int i = x - 1; i < N; i += x)
	{
		if (dir)
		{
			rotate(v[i].begin(), v[i].begin() + k, v[i].end());
		}
		else
		{
			rotate(v[i].rbegin(), v[i].rbegin() + k, v[i].rend());
		}
	}
}

void CheckC()
{
	vector<vector<int>> temp(v.begin(), v.end());
	set<pair<int, int>> e;
	int cnt{};
	for (auto& e : temp)
	{
		e.push_back(e.front());
	}
	for (int y = 0; y < N; y++)
	{
		for (int x = 0; x < M; x++)
		{
			for (int d = 0; d < 4; d++)
			{
				int ny = y + dy[d];
				int nx = x + dx[d];
				if (ny < 0 || nx < 0 || ny >=N || nx> M)
				{
					continue;
				}
				if (temp[y][x] == temp[ny][nx])
				{
					if (temp[y][x] == 0)
					{
						continue;
					}
					if (nx == M)
					{
						nx = 0;
					}
					e.insert({ y,x });
					e.insert({ ny,nx });
					cnt++;
				}
			}
		}
	}
	if (cnt)
	{
		for (auto c : e)
		{
			sum -= v[c.first][c.second];
			CCount--;
			v[c.first][c.second] = 0;
		}
	}
	else
	{
		float rev = (float)sum / CCount;
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				if (v[i][j] == 0)
				{
					continue;
				}
				if (v[i][j] > rev)
				{
					v[i][j]--;
					sum--;
				}
				else if(v[i][j] < rev)
				{
					v[i][j]++;
					sum++;
				}
			}
		}
	}

}

int main()
{
	cin >> N >> M >> T;
	for (int i = 0; i < N; i++)
	{
		vector<int> vv;
		for (int j = 0; j < M; j++)
		{
			cin >> a;
			sum += a;
			CCount++;
			vv.push_back(a);
		}
		v.push_back(vv);
	}
	for (int i = 0; i < T; i++)
	{
		cin >> x >> d >> k;
		Rotation(x, d, k);
		CheckC();
	}
	cout << sum;
}
