#include <bits/stdc++.h>

using namespace std;

int a[101][101];
int N,A,B;
int result;
int main()
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> A >> B;
		for (int i = A; i < A + 10; i++)
		{
			for (int j = B; j < B + 10; j++)
			{
				a[i][j] = 1;
			}
		}
	}

	for (int i = 0; i < 100; i++)
	{
		for (int j = 0; j < 100; j++)
		{
			result += a[i][j];
		}
	}

	cout << result;
}