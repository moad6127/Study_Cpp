#include <bits/stdc++.h>

using namespace std;

int n;
int a[26];
string s;
string result;
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> s;
		a[s[0] - 'a']++;
	}
	for (int i = 0; i < 26; i++)
	{
		if (a[i] >= 5)
		{
			result.push_back(i + 'a');
		}
	}
	if (result.empty())
	{
		cout << "PREDAJA";
	}
	else
	{
		cout << result;
	}
}