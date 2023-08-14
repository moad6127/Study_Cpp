#include <bits/stdc++.h>

using namespace std;

string input;

bool check(string input)
{
	stack<char> s;
	for (auto e : input)
	{
		if (e == '[')
		{
			s.push(e);
		}
		else if (e == ']')
		{
			if (!s.empty() && s.top() == '[')
			{
				s.pop();
			}
			else
			{
				return false;
			}
		}

		if (e == '(')
		{
			s.push(e);
		}
		else if (e == ')')
		{
			if (!s.empty() && s.top() == '(')
			{
				s.pop();
			}
			else
			{
				return false;
			}
		}
	}
	return s.empty();
}
int main()
{
	while (true)
	{
		getline(cin, input);
		if (input == ".")
		{
			break;
		}
		if (check(input))
		{
			cout << "yes" << '\n';
		}
		else
		{
			cout << "no" << '\n';
		}
	}
}