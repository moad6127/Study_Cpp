#include <bits/stdc++.h>	

using namespace std;

int t, n;
string s1, s2;
int main()
{
	cin >> t;
	for (int Time = 0; Time < t; Time++)
	{
		unordered_map<string, vector<string>> list;
		cin >> n;
		int result{ 1 };
		for (int i = 0; i < n; i++)
		{
			cin >> s1 >> s2;
			list[s2].push_back(s1);
		}
		for (auto e : list)
		{
			result = result * (e.second.size() + 1);
		}
		cout << result - 1<<'\n';
	}

}