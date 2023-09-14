#include <bits/stdc++.h>

using namespace std;

int N;
int result;
int main()
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		string s;
		cin >> s;

		stack<char> st;
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