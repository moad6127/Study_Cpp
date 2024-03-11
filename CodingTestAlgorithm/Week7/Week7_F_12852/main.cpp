#include <bits/stdc++.h>

using namespace std;

int X;
int a[1000004];

void Func(int X)
{
	if (X == 0)
	{
		return;
	}
	cout << X << " ";
	if (!(X % 3) && a[X] == (a[X / 3] + 1))
	{
		Func(X / 3);
	}
	else if (!(X % 2) && a[X] == (a[X / 2] + 1))
	{
		Func(X / 2);
	}
	else if ((X >= 1) && (a[X] == (a[X - 1] + 1)))
	{
		Func(X - 1);
	}
}

int main()
{
	cin >> X;
	fill(a,a + 1000004,987654321);
	a[1] = 0;
	for (int i = 1; i <= X; i++)
	{
		if (!(i % 3))
		{
			a[i] = min(a[i / 3] + 1, a[i]);
		}
		if (!(i % 2))
		{
			a[i] = min(a[i / 2] + 1, a[i]);
		}
		a[i] = min(a[i - 1] + 1, a[i]);
	}
	cout << a[X]<<'\n';
	Func(X);
}