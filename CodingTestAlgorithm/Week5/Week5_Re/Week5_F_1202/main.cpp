#include <bits/stdc++.h>

using namespace std;

long long n, m, v, k, c;
long long result;
vector<long long> back;
vector<pair<long long, long long>> ju;
int main()
{
	cin >> n >> k;
	for (int i = 0; i < n;i++)
	{
		cin >> m >> v;
		ju.push_back({ m,v });
	}
	for (int i = 0; i < k;i++)
	{
		cin >> c;
		back.push_back(c);
	}
	sort(ju.begin(), ju.end());
	sort(back.begin(), back.end());

	priority_queue<long long> pq;
	int j{};
	for (int i = 0; i < k;i++)
	{
		while (j < n && ju[j].first <= back[i])
		{
			pq.push(ju[j++].second);
		}
		if (pq.size())
		{
			result += pq.top();
			pq.pop();
		}
	}

	cout << result;
}