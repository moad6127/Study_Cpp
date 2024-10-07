#include <bits/stdc++.h>	

using namespace std;

int n;
string s;

bool Func(string s)
{
	stack<char> st;
	for (auto e : s)
	{
		if (st.size() && e == ')')
		{
			st.pop();
			continue;
		}
		else if(e ==')')
		{
			return false;
		}
		st.push(e);
	}
	if (st.size())
	{
		return false;
	}
	return true;
}
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> s;
		if (Func(s))
		{
			cout << "YES" << '\n';
		}
		else
		{
			cout << "NO" << '\n';
		}
	}
}