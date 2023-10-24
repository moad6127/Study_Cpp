#include <bits/stdc++.h>

using namespace std;

long long N, temp;
long long result;
stack<pair<long long, long long>> st;

int main()
{
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> temp;
		int cnt = 1;
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