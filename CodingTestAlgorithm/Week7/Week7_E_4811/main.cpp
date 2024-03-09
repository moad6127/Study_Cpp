#include <bits/stdc++.h>

using namespace std;
int N;
long long a[64][64];

long long Func(int half,int one)
{
	if (half == 0 && one == 0)
	{
		return 1;
	}
	if (a[half][one])
	{
		return a[half][one];
	}
	if (!half)
	{
		a[half][one] = Func(half + 1, one - 1);
		return a[half][one];
	}
	if (!one)
	{
		a[half][one] = Func(half - 1, one);
		return a[half][one];
	}
	a[half][one] = Func(half - 1, one) + Func(half + 1, one - 1);

	return a[half][one];
}
int main()
{
	while (true)
	{
		cin >> N;
		if (!N)
		{
			break;
		}
		cout << Func(1,N - 1)<<'\n';
	}
}