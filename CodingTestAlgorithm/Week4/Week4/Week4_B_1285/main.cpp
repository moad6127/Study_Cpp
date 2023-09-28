#include <bits/stdc++.h>

using namespace std;

int N;
int a[44];
int result = 1000000000;

void Func(int h)
{
	if (h == N)
	{
		int sum{};
		for (int i = 1; i <= (1 << (N - 1)); i *= 2)
		{
			int cnt{};
			for (int j = 0; j < N; j++)
			{
				if (a[j] & i)
				{
					cnt++;
				}
			}
			sum += min(cnt, N - cnt);
		}
		result = min(result, sum);
		return;
	}
	Func(h + 1);
	a[h] = ~a[h];
	Func(h + 1);
}
int main()
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		string s;
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
	Func(0);
	cout << result;
}