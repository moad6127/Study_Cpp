#include <bits/stdc++.h>

using namespace std;

int A, B, result;
unordered_map<int, int> mp;
int main()
{
	cin >> A >> B;
	for (int i = 0; i < A +B;i++)
	{
		int temp{};
		cin >> temp;
		mp[temp]++;
	}
	for (auto e : mp)
	{
		if (e.second == 1)
		{
			result++;
		}
	}
	cout << result;
}