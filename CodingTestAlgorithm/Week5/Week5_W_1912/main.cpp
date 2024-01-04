#include <bits/stdc++.h>

using namespace std;

int N,sum,a;
int result = -100000;
int main()
{
	cin >> N;
	for (int i = 0; i < N; i++)
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