#include <bits/stdc++.h>

using namespace std;
int N;
string s;
int result;
int Ncount[200001];
stack<int> st;
int main()
{
	cin >> N >> s;
	int checkCount{};
	for (int i = 0; i < N; i++)
	{
		if (s[i] == '(')
		{
			st.push(i);
		}
		else if (st.size())
		{
			Ncount[i] = 1;
			Ncount[st.top()] = 1;
			st.pop();
		}
	}
	for (int i = 0; i < N; i++)
	{
		if (Ncount[i])
		{
			checkCount++;
			result = max(result, checkCount);
		}
		else
		{
			checkCount = 0;
		}
	}
	cout << result;
}