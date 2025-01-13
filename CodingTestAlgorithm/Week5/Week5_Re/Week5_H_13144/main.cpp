#include <bits/stdc++.h>

using namespace std;

int n;
long long a[100001] , cnt[100001];
long long st, e, result;

int main()
{
	cin >> n;
	for (int i = 0;i < n;i++)
	{
		cin >> a[i];
	}
	while (e < n)
	{
		if (!cnt[a[e]])
		{
			cnt[a[e]]++;
			e++;
		}
		else
		{
			result += (e - st);
			cnt[a[st]]--;
			st++;
		}
	}

	result += (long long)(e - st) * (e - st + 1) / 2;
	cout << result;
}