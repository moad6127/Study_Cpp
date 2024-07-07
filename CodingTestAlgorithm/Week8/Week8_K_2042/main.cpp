#include<bits/stdc++.h>

using namespace std;

int N, M, K;
int A, B, C;

long long Sum(vector<long long>& tree, int i)
{
	long long result{};
	while (i > 0)
	{
		result += tree[i];
		i -= (i & -i);
	}
	return result;
}
void Update(vector<long long>& tree, int idx, long long val)
{
	while (idx <tree.size())
	{
		tree[idx] += val;
		idx += (idx & -idx);
	}
}

int main()
{
	cin >> N >> M >> K;
	vector<long long> a(N + 1);
	vector<long long> tree(N + 1);
	for (int i = 1; i <= N; i++)
	{
		cin >> a[i];
		Update(tree,i, a[i]);
	}
	for (int i = 0; i < M + K; i++)
	{
		cin >> A >> B >> C;
		if (A == 1)
		{
			long long temp = C - a[B];
			a[B] = C;
			Update(tree,B, temp);
		}
		else
		{
			cout << Sum(tree,C) - Sum(tree,B - 1) << '\n';
		}
	}
}