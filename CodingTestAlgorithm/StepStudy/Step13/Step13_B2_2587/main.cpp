#include <bits/stdc++.h>

using namespace std;

int a[5];
int sum;
int main()
{
	for (int i = 0; i < 5; i++)
	{
		cin >> a[i];
		sum += a[i];
	}
	sort(a, a + 5);
	cout << sum / 5 << '\n';
	cout << a[2] << '\n';

}