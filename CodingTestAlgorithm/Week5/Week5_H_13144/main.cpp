#include <bits/stdc++.h>

using namespace std;
int N;
long long a[100004], c[100004];
long long result, start, e;

int main()
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> a[i];
	}
	while (e < N)
	{
		if (!c[a[e]])
		{
			c[a[e]]++;
			e++;
		}
		else
		{
			result += (e - start);
			c[a[start]]--;
			start++;
		}
	}
	result += (long long)(e - start) * (e - start + 1) / 2;
	cout << result;
}