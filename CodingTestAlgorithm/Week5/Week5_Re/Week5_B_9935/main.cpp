#include <bits/stdc++.h>

using namespace std;


string s;
string checkS;
string result;
stack<char>st;
int main()
{
	cin >> s >> checkS;
	for (auto e : s)
	{
		st.push(e);
		if (st.top() == checkS.back())
		{
			if (st.size() >= checkS.size())
			{
				string temp;
				for (int i = 0; i < checkS.size();i++)
				{
					temp.push_back(st.top());
					st.pop();
				}
				reverse(temp.begin(), temp.end());
				if (temp != checkS)
				{
					for (int i = 0; i < temp.size();i++)
					{
						st.push(temp[i]);
					}
				}
			}
		}
	}
	while (st.size())
	{
		result += st.top();
		st.pop();
	}
	if (result.empty())
	{
		result = "FRULA";
	}
	else
	{
		reverse(result.begin(), result.end());
	}
	cout << result;
}