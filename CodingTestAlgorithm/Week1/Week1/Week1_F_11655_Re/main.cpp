#include <bits/stdc++.h>


using namespace std;


string a;
int main()
{
	getline(cin, a);

	for (auto& e : a)
	{
		if (e >= 'A' && e <= 'Z')
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
		else if (e >= 'a' && e <= 'z')
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
	}
	cout << a;
}