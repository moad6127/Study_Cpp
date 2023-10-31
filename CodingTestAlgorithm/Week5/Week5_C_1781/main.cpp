#include <bits/stdc++.h>

using namespace std;
int N,D,C,result;
vector <pair<int, int>> a;
priority_queue<int, vector<int>, greater<int>> pq;
int main()
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> D >> C;
		a.push_back({ D,C });
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
		result += pq.top();
		pq.pop();
	}
	cout << result;
}