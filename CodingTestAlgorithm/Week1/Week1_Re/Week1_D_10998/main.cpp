#include <bits/stdc++.h>

using namespace std;

string s;

int main()
{
	cin >> s;
	string temps = s;
	reverse(s.begin(), s.end());
	if (temps == s)
	{
		cout << 1;
	}
	else
	{
		cout << 0;
	}
}