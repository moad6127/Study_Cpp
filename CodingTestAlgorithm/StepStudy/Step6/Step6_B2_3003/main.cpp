#include <bits/stdc++.h>

using namespace std;
vector<int> a{1, 1, 2, 2, 2, 8};
vector<int> b;

int main()
{
	for (int i = 0; i < a.size(); i++)
	{
		int temp{};
		cin >> temp;
		b.push_back(a[i] - temp);
	}
	for (auto e : b)
	{
		cout << e << " ";
	}
}