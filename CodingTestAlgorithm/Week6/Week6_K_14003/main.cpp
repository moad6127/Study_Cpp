#include <bits/stdc++.h>

using namespace std;

int N, num,len;
int a[1000004];
pair<int, int> result[1000004];
const int MAX = 1000000004;
stack<int> st;
int main()
{
	cin >> N;
	fill(a, a + 1000004, MAX);
	for (int i = 0; i < N; i++)
	{
		cin >> num;
		auto lowerPos = lower_bound(a, a + len, num);
		int _pos = (int)(lower_bound(a, a + len, num) - a);
		if (*lowerPos == MAX)
		{
			len++;
		}
		*lowerPos = num;
		result[i].first = _pos;
		result[i].second = num;
	}
	cout << len << '\n';
	for (int i = N - 1; i >= 0; i--)
	{
		if (result[i].first == len - 1)
		{
			st.push(result[i].second);
			len--;
		}
	}
	while (st.size())
	{
		cout << st.top()<<" ";
		st.pop();
	}
}