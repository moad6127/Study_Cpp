#include <bits/stdc++.h>

using namespace std;
map<int, int> X, Y;
int A, B;
int main()
{
	for (int i = 0; i < 3; i++)
	{
		cin >> A >> B;
		X[A]++;
		Y[B]++;
	}
	for (auto e : X)
	{
		if (e.second % 2)
		{
			cout << e.first<<" ";
		}
	}
	for (auto e : Y)
	{
		if (e.second % 2)
		{
			cout << e.first<<" ";
		}
	}
}