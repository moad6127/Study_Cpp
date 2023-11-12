#include <bits/stdc++.h>

using namespace std;
int temp;
bool a[32];
int main()
{
	for (int i = 0; i < 28; i++)
	{
		cin >> temp;
		a[temp] = true;
	}

	for (int i = 1; i <= 30; i++)
	{
		if (!a[i])
		{
			cout << i << '\n';
		}
	}

}