#include <bits/stdc++.h>

using namespace std;

int main()
{
	int A{}, B{}, C{};
	cin >> A >> B >> C;
	vector<int> list(101, 0);
	int sum{};
	for (int i = 0; i < 3; i++)
	{
		int in{}, out{};
		cin >> in >> out;
		for (int j = in; j < out; j++)
		{
			list[j]++;
		}
	}

	for (auto e : list)
	{
		if (e == 0)
		{
			continue;
		}
		else if (e == 1)
		{
			sum += A;
		}
		else if (e == 2)
		{
			sum += (B * 2);
		}
		else if (e == 3)
		{
			sum += (C * 3);
		}
	}
	cout << sum;
}