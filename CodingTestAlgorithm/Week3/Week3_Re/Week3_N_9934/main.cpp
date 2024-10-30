#include <bits/stdc++.h>

using namespace std;

int k;
int a[1025];
int check[1025];

void Func(int here, int left, int right)
{
	if (here > k)
	{
		return;
	}
	int pIndex = (left + right) / 2;
	check[pIndex] = here;
	Func(here + 1, left, pIndex - 1);
	Func(here + 1, pIndex + 1, right);
}
int main()
{
	cin >> k;
	int size = pow(2, k);
	int le{};
	int rig{};
	for (int i = 0; i < size - 1; i++)
	{
		cin >> a[i];
		rig = max(rig, a[i]);
	}
	Func(1, le, rig);
	for (int i = 1; i <= k; i++)
	{
		for (int j = 0; j < rig; j++)
		{
			if (check[j] == i)
			{
				cout << a[j] << " ";
			}
		}
		cout << '\n';
	}
}