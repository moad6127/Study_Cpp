#include <bits/stdc++.h>

using namespace std;

const vector<string> PICACHU{ {"pi"},{"ka"},{"chu"} };

string s;
int main()
{
	cin >> s;
	while (s.size())
	{
		int num = s.size();
		for (int i = 0; i < 3;i++)
		{
			if (s.find(PICACHU[i]) == 0)
			{
				s = s.substr(PICACHU[i].size());
			}
		}
		if (num == s.size())
		{
			break;
		}
	}
	if (s.size())
	{
		cout << "NO";
	}
	else
	{
		cout << "YES";
	}
}