#include <bits/stdc++.h>

using namespace std;

int N, K;
vector<int> a;
int main()
{
	cin >> N >> K;
	for (int i = 1; i <= N; i++)
	{
		if (N % i == 0)
		{
			a.push_back(i);
		}
	}
	if (a.size() > K - 1)
	{
		cout << a[K - 1];
	}
	else
	{
		cout << 0;
	}

}