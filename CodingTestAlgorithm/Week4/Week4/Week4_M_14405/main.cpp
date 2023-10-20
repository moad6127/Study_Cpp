#include  <bits/stdc++.h>

using namespace std;
string s;
vector<string> checkS{ "pi", "ka", "chu" };

bool Func(string input)
{
	if (input.size() == 0)
	{
		return true;
	}
	for (auto e : checkS)
	{
		if (input.find(e) == 0)
		{
			string nextS = input.substr(e.length());
			if (Func(nextS))
			{
				return true;
			}
		}
	}
	return false;
}

int main()
{
	cin >> s;
	if (Func(s))
	{
		cout << "YES";
	}
	else
	{
		cout << "NO";
	}
}