#include <bits/stdc++.h>

using namespace std;

int a, b;
map<int, int> m;
int result;
int main()
{
	cin >> a >> b;
	for (int i = 0; i < a + b; i++)
	{
		int temp{};
		cin >> temp;
		m[temp]++;
	}
	for (auto e : m)
	{
		if (e.second == 1)
		{
			result++;
		}
	}
	cout << result;
}