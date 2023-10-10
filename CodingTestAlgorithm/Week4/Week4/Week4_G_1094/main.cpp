#include <bits/stdc++.h>

using namespace std;

int X;
int result;
int main()
{
	cin >> X;
	for (int i = 0; i <= 6; i++)
	{
		if (X & (1 << i))
		{
			result++;
		}
	}
	cout << result;
}