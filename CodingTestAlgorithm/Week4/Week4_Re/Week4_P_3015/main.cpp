#include <bits/stdc++.h>

using namespace std;

long long n, temp;
long long result;
stack<pair<long long, long long>> st;
int main()
{
	cin >> n;
	for (int i = 0;i < n;i++)
	{
		cin >> temp;
		int cnt{ 1 };
		while (st.size() && st.top().first <= temp)
		{
			result += st.top().second;
			if (st.top().first == temp)
			{
				cnt = st.top().second + 1;
			}
			else
			{
				cnt = 1;
			}
			st.pop();
		}
		if (st.size())
		{
			result++;
		}
		st.push({ temp,cnt });
	}
	cout << result;
}