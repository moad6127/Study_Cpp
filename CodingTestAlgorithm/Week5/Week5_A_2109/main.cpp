#include <bits/stdc++.h>

using namespace std;
int N;
int d, p;
int result;
vector<pair<int, int>> a;
priority_queue<int, vector<int>, greater<int>> pq;
int main()
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> p >> d;
		a.push_back({ d,p });
	}
	sort(a.begin(), a.end());
	for (int i = 0; i < N; i++)
	{
		pq.push(a[i].second);
		if (pq.size() > a[i].first)
		{
			pq.pop();
		}
	}
	while (pq.size())
	{
		result += pq.top(); pq.pop();
	}
	cout << result;
}