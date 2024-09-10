#include <bits/stdc++.h>

using namespace std;

string s;
int a[26];

int main()
{
	cin >> s;
	for (auto e : s)
	{
		a[e - 'a']++;
	}

	for (auto e : a)
	{
		cout << e << " ";
	}
}