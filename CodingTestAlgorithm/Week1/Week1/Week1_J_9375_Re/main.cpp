#include <bits/stdc++.h>

using namespace std;
int T;

int main()
{	
	cin >> T;
	for (int i = 0; i < T; i++)
	{
		int S{};
		string c, p;
		map<string, vector <string>> Clist;
		long long result{1};
		cin >> S;
		for (int j = 0; j < S; j++)
		{
			cin >> c >> p;
			Clist[p].push_back(c);
		}
		for (auto e : Clist)
		{
			result *= (long long)e.second.size() + 1;
		}
		cout << result - 1 << '\n';
	}

}