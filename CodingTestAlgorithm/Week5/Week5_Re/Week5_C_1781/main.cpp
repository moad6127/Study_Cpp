#include <bits/stdc++.h>	

using namespace std;

int n, result;
int c, d;

vector<pair<int, int>> v;
priority_queue<int,vector<int>,greater<>> pq;
int main()
{
	cin >> n;
	for (int i = 0; i < n;i++)
	{
		cin >> d >> c;
		v.push_back({ d,c });
	}
	sort(v.begin(), v.end());

	for (int i = 0; i < v.size();i++)
	{
		pq.push(v[i].second);
		if (v[i].first < pq.size())
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