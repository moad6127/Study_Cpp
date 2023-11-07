#include <bits/stdc++.h>

using namespace std;
int N, X;
vector<int> a;
int main()
{
	cin >> N >> X;
	for (int i = 0; i < N; i++)
	{
		int temp{};
		cin >> temp;
		a.push_back(temp);
	}
	for (auto e : a)
	{
		if (e < X)
		{
			cout << e << " ";
		}
	}
}