#include <bits/stdc++.h>

using namespace std;
int N;
vector<pair<int,string>> v;
bool Comp(pair<int, string> a, pair<int, string> b)
{
	return a.first < b.first;
}

int main()
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		pair<int, string> temp;
		cin >> temp.first >> temp.second;
		v.push_back(temp);
	}
	stable_sort(v.begin(), v.end(),Comp);
	for (auto e : v)
	{
		cout << e.first << " " << e.second << '\n';
	}
}