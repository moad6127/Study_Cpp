#include <bits/stdc++.h>

using namespace std;

int main()
{
	int num{};
	cin >> num;
	for (int i = 0; i < num; i++)
	{
		map<string, vector<string>> list;
		int count{};
		cin >> count;
		long long sum{1};
		for (int j = 0; j < count; j++)
		{
			string cloth, kind;
			cin >> cloth >> kind;
			list[kind].push_back(cloth);
		}

		for (auto e : list)
		{
			sum *= ((long long)e.second.size() + 1);
		}
		cout << --sum << '\n';

	}
}