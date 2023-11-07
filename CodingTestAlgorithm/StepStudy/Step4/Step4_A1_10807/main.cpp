#include <bits/stdc++.h>

using namespace std;

int N;
int a[204];
int temp;
int result;
int main()
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> temp;
		a[temp + 100]++;
	}
	cin >> result;
	cout << a[result + 100];
}