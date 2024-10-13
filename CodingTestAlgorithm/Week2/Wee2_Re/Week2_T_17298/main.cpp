#include <bits/stdc++.h>

using namespace std;

int n, a;
stack<pair<int, int>> st;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	vector<int> ans(n, -1);
	for (int i = 0; i < n; i++)
	{
		cin >> a;
		if (st.size())
		{
			while (true)
			{
				if (st.empty())
				{
					break;
				}
				if (st.top().first >= a)
				{
					break;
				}
				ans[st.top().second] = a;
				st.pop();
			}
		}
		st.push({ a,i });
	}
	for (int i = 0; i < n; i++)
	{
		cout << ans[i] << ' ';
	}
}