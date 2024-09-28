#include <bits/stdc++.h>

using namespace std;

int n, c;
int a;
unordered_map<int, pair<int, int>> li;

bool Comp(pair<int, pair<int, int>>& a, pair<int, pair<int, int>>& b)
{
	if (a.second.first == b.second.first)
	{
		return a.second.second < b.second.second;
	}
	return a.second.first > b.second.first;
}

int main()
{
	cin >> n >> c;
	for (int i = 0; i < n; i++)
	{
		cin >> a;
		if (li.count(a))
		{
			li[a].first++;
		}
		else
		{
			li[a].first++;
			li[a].second = i;
		}
	}
	vector<pair<int, pair<int, int>>> t(li.begin(), li.end());

	sort(t.begin(), t.end(), Comp);
	for (int i = 0; i < t.size(); i++)
	{
		for (int j = 0; j < t[i].second.first; j++)
		{
			cout << t[i].first << " ";
		}
	}

}