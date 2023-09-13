#include <bits/stdc++.h>

using namespace std;

int a[10];
int sum;

void print()
{
	for (int i = 0; i < 7; i++)
	{
		cout << a[i] << '\n';
	}
}
int main()
{
	for (int i = 0; i < 9; i++)
	{
		cin >> a[i];
		sum += a[i];
	}

	for (int i = 0; i < 9; i++)
	{
		int check = sum;
		for (int j = i + 1; j < 9; j++)
		{
			if (check - a[i] - a[j] == 100)
			{
				a[i] = 1000;
				a[j] = 1000;
				sort(a, a + 9);
				print();
				return 0;
			}
		}
	}
}