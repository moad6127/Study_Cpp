#include <bits/stdc++.h>

using namespace std;
string s;
int main()
{
	getline(cin, s);
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] >= 'A' && s[i] <= 'Z')
		{
			if (s[i] + 13 > 90)
			{
				s[i] = s[i] + 13 - 26;
			}
			else
			{
				s[i] = s[i] + 13;
			}
		}
		else if (s[i] >= 'a' && s[i] <= 'z')
		{
			if (s[i] + 13 > 122)
			{
				s[i] = s[i] + 13 - 26;
			}
			else
			{
				s[i] = s[i] + 13;
			}
		}
	}
	cout << s;
}