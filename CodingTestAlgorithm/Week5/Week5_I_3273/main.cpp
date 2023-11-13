#include<bits/stdc++.h>

using namespace std;
int N,X;
int a[100004];
int start, e;
int result;
int main()
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> a[i];
	}
	cin >> X;
	e = N - 1;
	sort(a, a + N);

	while (true)
	{
		if (start >= e)
		{
			break;
		}
		int sum{a[start] + a[e]};
		if (sum > X)
		{
			e--;
		}
		else if (sum < X)
		{
			start++;
		}
		else
		{
			result++;
			start++;
		}

	}

	cout << result;
	return 0;
}