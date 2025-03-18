#include <bits/stdc++.h>

using namespace std;

int n, result = INT_MIN, sum;
int a;
int main()
{
	cin >> n;
	for (int i = 1;i <= n;i++)
	{
		cin >> a;
		sum += a;
		result = max(result, sum);
		if (sum < 0)
		{
			sum = 0;
		}

	}
	cout << result;

}