#include <bits/stdc++.h>

using namespace std;

long long n, resultMax = INT_MIN, resultMin = INT_MAX;
int a[14];

long long Op(long long a, long long b, int op)
{
	long long result{};
	switch (op)
	{
	case 0:
		result = a + b;
		break;

	case 1:
		result = a - b;
		break;
	case 2:
		result = a * b;
		break;
	case 3:
		result = a / b;
		break;
	}
	return result;
}
void Func(int here, long long nums, vector<int> oper)
{
	if (here >= n)
	{
		resultMax = max(nums, resultMax);
		resultMin = min(nums, resultMin);
		return;
	}
	for (int i = 0; i < 4;i++)
	{
		if (oper[i])
		{
			oper[i]--;
			Func(here + 1,Op(nums,a[here], i), oper);
			oper[i]++;
		}
	}
}

int main()
{
	vector<int> oper(4,0);
	cin >> n;
	for (int i = 0; i < n;i++)
	{
		cin >> a[i];
	}
	for (int i = 0; i < 4;i++)
	{
		cin >> oper[i];
	}
	Func(1, a[0], oper);
	cout << resultMax << '\n';
	cout << resultMin;
}