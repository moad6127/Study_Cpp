#include <bits/stdc++.h>

using namespace std;

int S;
int m, num;
string op;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> m;
	for (int i = 0; i < m; i++)
	{
		cin >> op;
		if (op == "add")
		{
			cin >> num;
			S |= (1 << num);
		}
		else if (op == "remove")
		{
			cin >> num;
			S &= ~(1 << num);
		}
		else if (op == "check")
		{
			cin >> num;
			S& (1 << num) ? cout << 1 << '\n' : cout << 0 << '\n';
		}
		else if (op == "toggle")
		{
			cin >> num;
			S ^= (1 << num);
		}
		else if (op == "all")
		{
			S = INT_MAX - 1;
		}
		else if (op == "empty")
		{
			S = 0;
		}
	}
}