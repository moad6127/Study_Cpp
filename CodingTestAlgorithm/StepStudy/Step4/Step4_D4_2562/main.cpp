#include <bits/stdc++.h>

using namespace std;

int a[10];
pair<int, int> result;
int main()
{
	for (int i = 1; i <= 9; i++)
	{
		cin >> a[i];
		if (result.first < a[i])
		{
			result.first = a[i];
			result.second = i;
		}
	}
	cout << result.first << '\n';
	cout << result.second;
}