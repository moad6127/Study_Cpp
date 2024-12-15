#include <bits/stdc++.h>	

using namespace std;

int n, d[200001], result ,cnt;
stack<int> st;
string s;
int main()
{
	cin >> n >> s;

	for (int i = 0; i < n;i++)
	{
		if (s[i] == '(')
		{
			st.push(i);
		}
		else if (st.size())
		{
			d[i] = d[st.top()] = 1;
			st.pop();
		}
	}
	for (int i = 0; i < n;i++)
	{
		if (d[i])
		{
			cnt++;
			result = max(result, cnt);
		}
		else
		{
			cnt = 0;
		}

	}
	cout << result;
}