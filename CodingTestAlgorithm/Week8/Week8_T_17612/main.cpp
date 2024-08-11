#include <bits/stdc++.h>

using namespace std;

int n, k, cnt = 1;
long long result;
int id, needT, nowT;

struct info {
	int id;
	int maxTime;
	int cacher_id;
};
struct comp {
	bool operator()(info& a, info& b)
	{
		if (a.maxTime == b.maxTime)
		{
			return a.cacher_id > b.cacher_id;
		}
		return a.maxTime > b.maxTime;
	}
};
vector<info>v;
bool comp2(info& a, info& b)
{
	if (a.maxTime == b.maxTime)
	{
		return a.cacher_id > b.cacher_id;
	}
	return a.maxTime < b.maxTime;
}

int main()
{

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);



	cin >> n >> k;
	priority_queue<info, vector<info>, comp> pq;
	for (int i = 0; i < n; i++)
	{
		cin >> id >> needT;
		if (i < k)
		{
			pq.push({ id,needT,i + 1 });
			continue;
		}
		pq.push({ id,needT + pq.top().maxTime,pq.top().cacher_id });
		v.push_back(pq.top());
		pq.pop();
	}
	while (pq.size())
	{
		v.push_back(pq.top());
		pq.pop();
	}
	sort(v.begin(), v.end(), comp2);
	for (int i = 0; i < v.size(); i++)
	{
		result += (long long)(i + 1) * v[i].id;
	}

	cout << result;
}