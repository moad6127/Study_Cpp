#include <bits/stdc++.h>

using namespace std;

int n, result;
string s;

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		stack<char>st;
		cin >> s;
		for (auto e : s)
		{
			if (st.empty())
			{
				st.push(e);
			}
			else
			{
				if (st.top() == e)
				{
					st.pop();
				}
				else
				{
					st.push(e);
				}
			}
		}
		if (st.empty())
		{
			result++;
		}
	}
	cout << result;
}