#include <bits/stdc++.h>

using namespace std;
int N,D,C,result;
int a[200001];

int main()
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> D >> C;
		a[D] = max(a[D], C);
	}
	for (int i = 0; i <= N; i++)
	{
		result += a[i];
	}
	cout << result;
}