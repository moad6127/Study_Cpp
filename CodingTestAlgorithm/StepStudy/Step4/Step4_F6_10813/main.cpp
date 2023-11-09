#include <bits/stdc++.h>

using namespace std;
int N,M;
int a[104];
int A, B;
int main()
{
	cin >> N >> M;
	for (int i = 1; i <= N; i++)
	{
		a[i] = i;
	}

	for (int i = 0; i < M; i++)
	{
		cin >> A >> B;
		swap(a[A], a[B]);
	}
	for (int i = 1; i <= N; i++)
	{
		cout << a[i] << " ";
	}
}