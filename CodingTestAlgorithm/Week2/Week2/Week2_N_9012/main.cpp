#include <bits/stdc++.h>

using namespace std;

int N;
string input;

bool check(string input)
{
	stack<char> s;

	for (auto e : input)
	{
		if (e == '(')
		{
			s.push(e);
		}
		else
		{
			if (!s.empty())
			{
				s.pop();
			}
			else
			{
				return false;
			}
		}
	}
	return s.empty();
}
int main()
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> input;
		if (check(input))
		{
			cout << "YES" << '\n';
		}
		else
		{
			cout << "NO" << '\n';
		}
	}
}