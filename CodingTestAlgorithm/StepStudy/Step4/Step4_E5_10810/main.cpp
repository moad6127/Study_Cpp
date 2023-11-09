#include <bits/stdc++.h>

using namespace std;

int N, M;
int a[104];
int A, B, C;
int main()
{
	cin >> N >> M;
	for (int i = 0; i < M; i++)
	{
		cin >> A >> B >> C;
		for (int j = A; j <= B; j++)
		{
			a[j] = C;
		}
	}

	for (int i = 1; i <= N; i++)
	{
		cout << a[i]<<" ";
	}
}