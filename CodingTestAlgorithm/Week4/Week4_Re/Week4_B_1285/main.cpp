#include <bits/stdc++.h>

using namespace std;

int n;
int a[44];
string s;
int result = 987654321;
void Func(int here)
{
	if (here == n + 1)
	{
		int sum{};
		for (int i = 1; i <= (1 << (n - 1)); i *= 2)
		{
			int cnt{};
			for (int j = 1; j <= n; j++)
			{
				if (a[j] & i)
				{
					cnt++;
				}
			}
			sum += min(cnt, n - cnt);
		}
		result = min(result, sum);
		return;
	}

	Func(here + 1);
	a[here] = ~a[here];
	Func(here + 1);
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> s;
		int value{ 1 };
		for (int j = 0; j < s.size(); j++)
		{
			if (s[j] == 'T')
			{
				a[i] |= value;
			}
			value *= 2;
			
		}
	}
	Func(1);
	cout << result;
}