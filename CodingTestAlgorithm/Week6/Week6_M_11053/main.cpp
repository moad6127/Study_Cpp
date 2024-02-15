#include <bits/stdc++.h>

using namespace std;

int N;
int a[1004], result, num;
int main()
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> num;
		auto lowerPos = lower_bound(a, a + result, num);
		if (*lowerPos == 0)
		{
			result++;
		}
		*lowerPos = num;
	}
	cout << result;
}