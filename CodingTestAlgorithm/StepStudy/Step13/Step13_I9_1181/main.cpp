#include <bits/stdc++.h>

using namespace std;

int N;
set<string> s;

bool Comp(string& a, string& b)
{
	if (a.size() == b.size())
	{
		return a < b;
	}
	return a.size() < b.size();
}

int main()
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		string temp{};
		cin >> temp;
		s.insert(temp);
	}
	vector<string> vv(s.begin(), s.end());
	sort(vv.begin(), vv.end(), Comp);
	for (auto e : vv)
	{
		cout << e << '\n';
	}
}