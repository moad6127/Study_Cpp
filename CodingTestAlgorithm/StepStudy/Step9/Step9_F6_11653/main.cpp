#include <bits/stdc++.h>

using namespace std;

int N;

int main()
{
	cin >> N;

	if (N == 1)
	{
		return 0;
	}
	int i{ 2 };
	while (true)
	{
		if (N < 2)
		{
			break;
		}
		if (N % i == 0)
		{
			N /= i;
			cout << i << '\n';
		}
		else
		{
			i++;
		}
	}
}