#include <bits/stdc++.h>

using namespace std;

int main()
{
	int count{}, need{};
	cin >> count >> need;
	int result{};
	vector<int> list(count, 0);
	for (int i = 0; i < count; i++)
	{
		cin >> list[i];
	}

	for (int i = 0; i < list.size(); i++)
	{
		int sum{};
		for (int j = i + 1; j < list.size(); j++)
		{
			sum = list[i] + list[j];
			if (sum == need)
			{
				result++;
			}
		}
	}
	cout << result;
}