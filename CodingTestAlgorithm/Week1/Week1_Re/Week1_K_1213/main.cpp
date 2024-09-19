#include <bits/stdc++.h>

using namespace std;

string s;
int a[26];
string fail{ "I'm Sorry Hansoo" };
string result;
int main()
{
	cin >> s;

	for (int i = 0; i < s.size(); i++)
	{
		a[s[i] - 'A']++;
	}
	for (int i = 0; i < 26; i++)
	{
		if (a[i] % 2 == 1)
		{
			if (!result.empty())
			{
				cout << fail;
				return 0;
			}
			result += i + 'A';
			a[i]--;
		}
	}
	for (int i = 25; i >= 0; i--)
	{
		if (a[i])
		{
			string temp(a[i]/2,i + 'A');
			result = temp + result + temp;
		}
	}
	cout << result;
	return 0;

}