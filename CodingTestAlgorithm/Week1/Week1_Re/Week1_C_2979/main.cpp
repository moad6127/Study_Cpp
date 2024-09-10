#include <bits/stdc++.h>

using namespace std;

int a[101];
int A, B, C;
int x, y;
int result;
int main()
{
	cin >> A >> B >> C;
	for (int i = 0; i < 3; i++)
	{
		cin >> x >> y;
		for (int i = x; i < y; i++)
		{
			a[i]++;
		}
	}
	for (int i = 0; i <= 100; i++)
	{
		if (a[i] == 1)
		{
			result += A;
		}
		else if (a[i] == 2)
		{
			result += (B * 2);
		}
		else if (a[i] == 3)
		{
			result += (C * 3);
		}
	}
	cout << result;
}