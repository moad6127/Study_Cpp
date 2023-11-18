#include<bits/stdc++.h>

using namespace std;

int N;
int main()
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		for (int j = N - 1; j >i;j--)
		{
			cout << " ";
		}
		for (int j = 0; j <=i ; j ++)
		{
			cout << "*";
		}
		for (int j = 1; j <= i; j++)
		{
			cout << "*";
		}
		cout << '\n';
	}
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			cout << " ";
		}
		for (int j = N - 1; j > i; j--)
		{
			cout << "*";
		}
		for (int j = N - 2; j > i; j--)
		{
			cout << "*";
		}
		cout << '\n';
	}
}