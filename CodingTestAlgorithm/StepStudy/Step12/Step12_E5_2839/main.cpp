#include <bits/stdc++.h>

using namespace std;

int N;
int a[5004];
int result;

void Func(int n, int count)
{
	if (n > 5000)
	{
		return;
	}
	if (a[n]!= -1)
	{
		return;
	}
	a[n] = count;
	Func(n + 5, count + 1);
	Func(n + 3, count + 1);
}
int main()
{
	cin >> N;
	fill(a, a + 5004, -1);
	Func(0, 0);
	cout << a[N];
}