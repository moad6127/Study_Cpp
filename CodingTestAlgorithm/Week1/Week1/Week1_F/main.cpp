#include <bits/stdc++.h>

using namespace std;

int main()
{
	string s;
	getline(cin, s);

	for (auto& e : s)
	{
		if ((e >= 'a' && e <= 'z') )
		{
			if (e > 'z' - 13)
			{
				e = e + 13 - 26;
			}
			else
			{
				e += 13;
			}
		}
		else if ((e >= 'A' && e <= 'Z'))
		{
			if (e > 'Z' - 13)
			{
				e = e + 13 - 26;
			}
			else
			{
				e += 13;
			}
		}
		else
		{
			continue;
		}
	}
	cout << s;
}