#include <bits/stdc++.h>

using namespace std;

set<int> a;
int temp;
int main()
{
	for (int i = 0; i < 10; i++)
	{
		cin >> temp;
		a.insert(temp % 42);
	}

	cout << a.size();
}