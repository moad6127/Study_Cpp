#include <bits/stdc++.h>

using namespace std;

long long a, b, c, result;

long long Func(long long nums, long long cnt)
{
	if (cnt == 1)
	{
		return (nums) % c;
	}
	if (cnt & 1)
	{
		return ((Func(nums, cnt / 2 + 1) % c) * (Func(nums, cnt / 2) % c) % c);
	}
	else
	{
		return ((Func(nums, cnt / 2) % c) * (Func(nums, cnt / 2) % c) % c);
	}
}

int main()
{
	cin >> a >> b >> c;

	cout << Func(a, b);
}