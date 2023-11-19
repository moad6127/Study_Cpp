#include <bits/stdc++.h>

using namespace std;

string s;
int a[26];
int maxA;
bool check;
char result;
int main()
{
	cin >> s;
	for (auto& e : s)
	{
		e = toupper(e);
		a[e - 'A']++;
		maxA = max(a[e - 'A'], maxA);
	}
	for (int i = 0; i < 26; i++)
	{
		if (maxA == a[i])
		{
			if (check)
			{
				cout << "?";
				return 0;
			}
			check = true;
			result = i + 'A';
		}
	}
	cout << result;
}
