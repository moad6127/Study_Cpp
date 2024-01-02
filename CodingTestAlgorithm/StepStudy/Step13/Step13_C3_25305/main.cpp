#include <bits/stdc++.h>

using namespace std;

int N, K;
int a[1004];
int main()
{
	cin >> N >> K;
	for (int i = 0; i < N; i++)
	{
		cin >> a[i];
	}
	sort(a, a + N,greater<>());

	cout << a[K - 1];

}