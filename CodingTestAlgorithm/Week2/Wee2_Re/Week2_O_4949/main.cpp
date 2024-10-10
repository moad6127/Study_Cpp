#include <bits/stdc++.h>

using namespace std;

string s;
bool Func(string s)
{
	stack<char> st;
	for (auto e : s)
	{
		if (e == '(' || e == ')' || e == '[' || e == ']')
		{
			if (e == ')')
			{
				if (st.empty() || st.top() == '[')
				{
					return false;
				}
				else
				{
					st.pop();
					continue;
				}
			}
			else if (e == ']')
			{
				if (st.empty() || st.top() == '(')
				{
					return false;
				}
				else
				{
					st.pop();
					continue;
				}
			}
			st.push(e);
		}
	}

	return st.empty();
}

int main()
{
	while (true)
	{
		getline(cin, s);
		if (s == ".")
		{
			break;
		}
		Func(s) ? cout << "yes" << '\n' : cout << "no" << '\n';
	}


}