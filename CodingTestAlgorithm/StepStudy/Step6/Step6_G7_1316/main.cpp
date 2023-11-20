#include <bits/stdc++.h>

using namespace std;

int N;
string s;
int result;
int main()
{
	cin >> N;
	for (int i = 0; i < N;i++)
	{
		cin >> s;
		char prevChar{};
		set<char> check;
		bool add{};
		for (auto e : s)
		{
			if (e != prevChar)
			{
				auto c = check.insert(e);
				if (!c.second)
				{
					add = true;
					break;
				}
				prevChar = e;

			}
		}
		if (!add)
		{
			result++;
		}
	}
	cout << result;

}