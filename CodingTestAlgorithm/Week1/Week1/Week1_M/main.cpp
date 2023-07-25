#include <bits/stdc++.h>

using namespace std;

int main()
{
	int num{}, result{};
	cin >> num;
	for (int i = 0; i < num; i++)
	{
		string input;
		cin >> input;
		stack<char> st;
		for (auto e : input)
		{
			if (!st.empty() && st.top() == e)
			{
				st.pop();
			}
			else
			{
				st.push(e);
			}
		}
		if (st.empty())
		{
			result++;
		}
	}
	cout << result;
}