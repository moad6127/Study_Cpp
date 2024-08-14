#include <bits/stdc++.h>

using namespace std;

int n, T = 1;
const int dy[] = { -1,0,1,0 };
const int dx[] = { 0,1,0,-1 };
int a[130][130];
int dist[130][130];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

int main()
{
	while(true)
	{
		cin >> n;
		if (n == 0)
		{
			break;
		}
		fill(&a[0][0], &a[0][0] + 130 * 130, 0);
		fill(&dist[0][0], &dist[0][0] + 130 * 130, 987654321);
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				cin >> a[i][j];
			}
		}
		pq.push({ a[0][0],0 });
		dist[0][0] = a[0][0];
		while (pq.size())
		{
			int herey = pq.top().second / 1000;
			int herex = pq.top().second % 1000;
			int here_Dist = pq.top().first;
			pq.pop();
			if (dist[herey][herex] != here_Dist)
			{
				continue;
			}
			for (int i = 0; i < 4; i++)
			{
				int ny = herey + dy[i];
				int nx = herex + dx[i];
				if (ny < 0 || ny >= n || nx < 0 || nx >= n)
				{
					continue;
				}
				int _dist = a[ny][nx];
				if (dist[ny][nx] > dist[herey][herex] + _dist)
				{
					dist[ny][nx] = dist[herey][herex] + _dist;
					pq.push({ dist[ny][nx],ny * 1000 + nx });
				}
			}
		}
		cout << "Problem " << T++ << ": " << dist[n - 1][n - 1]<<"\n";
	}
}