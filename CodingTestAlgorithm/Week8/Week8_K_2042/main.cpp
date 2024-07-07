#include<bits/stdc++.h>

using namespace std;

int N, M, K;
long long tree[1000004];
long long a[1000004];
long long A, B, C;

long long Sum(int i)
{
	long long result{};
	while (i > 0)
	{
		result += tree[i];
		i -= (i & -i);
	}
	return result;
}
void Update(int idx, long long val)
{
	while (idx <= 1000003)
	{
		tree[idx] += val;
		idx += (idx & -idx);
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M >> K;
	for (int i = 1; i <= N; i++)
	{
		cin >> a[i];
		Update(i, a[i]);
	}
	for (int test = 0; test < M + K; test++)
	{
		cin >> A >> B >> C;
		if (A == 1)
		{
			long long temp = C - a[B];
			a[B] = C;
			Update(B, temp);
		}
		else
		{
			cout << Sum(C) - Sum(B - 1)<<'\n';
		}
	}
}