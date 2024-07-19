#include <bits/stdc++.h>

using namespace std;

int n, m;
int a, b, c;
vector<pair<int, int>> adj[4004];
int px[4004];
int wo[4004][2];
int result;

struct Comp
{
	int dist;
	bool flag;
	int here;

};

bool operator<(Comp a, Comp b)
{
	return a.dist > b.dist;
}
void dijpx()
{
	fill(px, px + 4004, 987654321);
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push({ 0,1 });
	px[1] = 0;
	while (pq.size())
	{
		int here = pq.top().second;
		int here_dist = pq.top().first;
		pq.pop();
		if (px[here] != here_dist)
		{
			continue;
		}
		for (pair<int, int> there : adj[here]) {
			int _dist = there.first;
			int _there = there.second;
			if (px[_there] > px[here] + _dist) {
				px[_there] = px[here] + _dist;
				pq.push(make_pair(px[_there], _there));
			}
		}
	}
}
void dijwo()
{
	fill(&wo[0][0], &wo[0][0] + 4001 * 2, 987654321);
	priority_queue<tuple<int,int,bool>, vector<tuple<int, int, bool>>, greater<tuple<int, int, bool>>> PQ;
	wo[1][0] = 0;
	PQ.push(make_tuple(0, 1, 0));
	while (PQ.size()) {
		int d, here, cnt;
		tie(d, here, cnt) = PQ.top();
		PQ.pop();
		if (wo[here][cnt] != d) continue;
		for (pair<int, int> there : adj[here]) {
			int next = there.second;
			int d = !cnt ? there.first / 2 : there.first * 2;
			if (wo[next][!cnt] > wo[here][cnt] + d) {
				wo[next][!cnt] = wo[here][cnt] + d;
				PQ.push(make_tuple(wo[next][!cnt], next, !cnt));
			}
		}
	}
}
int main()
{
	cin >> n >> m;

	for (int i = 0; i < m; i++)
	{
		cin >> a >> b >> c;
		adj[a].push_back({ 100*c,b });
		adj[b].push_back({ 100 * c,a });
	}
	dijpx();
	dijwo();
	for (int i = 1; i <= n; i++)
	{
		if (px[i] < min(wo[i][0],wo[i][1]))
		{
			result++;
		}
	}
	cout << result;
}