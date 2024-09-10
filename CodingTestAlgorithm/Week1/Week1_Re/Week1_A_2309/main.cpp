#include <bits/stdc++.h>

using namespace std;

int v[10];
int sum{};

void FUNC1()
{
	for (int i = 0; i < 9; i++)
	{
		for (int j = i + 1; j < 9; j++)
		{
			int _Sum{ v[i] + v[j] };
			if (sum - _Sum == 100)
			{
				for (int k = 0; k < 9; k++)
				{
					if (k == i || k == j)
					{
						continue;
					}
					cout << v[k] << '\n';
				}
				return ;
			}
		}
	}
}
int main()
{
	for (int i = 0; i < 9; i++)
	{
		cin >> v[i];
		sum += v[i];
	}
	sort(v,v + 9);
}