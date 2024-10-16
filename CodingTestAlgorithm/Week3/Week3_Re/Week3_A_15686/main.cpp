#include <bits/stdc++.h>

using namespace std;
int n, m;
int a[51][51];
vector<pair<int, int>> h;
vector<pair<int, int>> c;
int result{ 987654321 };

void Func(vector<int> NRe)
{
	// 집집마다 치킨 거리 구하기
	int sum{};
	for (auto e : h)
	{
		int dis{987654321};
		for (auto k : NRe)
		{
			dis = min(dis,abs(e.first - c[k].first) + abs(e.second - c[k].second));
		}
		sum += dis;
	}
	result = min(result, sum);
}
void dfs(int here,vector<int> NRe)
{
	if (NRe.size() == m)
	{
		Func(NRe);
		return;
	}
	for (int i = here; i < c.size(); i++)
	{
		NRe.push_back(i);
		dfs(i + 1, NRe);
		NRe.pop_back();
	}
}
int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> a[i][j];
			if (a[i][j] == 1)
			{
				h.push_back({ i,j });
			}
			if (a[i][j] == 2)
			{
				c.push_back({ i,j });
			}
		}
	}
	dfs(0, vector<int>());
	cout << result;
}