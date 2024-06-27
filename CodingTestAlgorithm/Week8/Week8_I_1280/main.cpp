#include <bits/stdc++.h>

using namespace std;

int N, value;
long long MOD{ 1000000007 }, result{1};

vector<long long> tree_cnt(200005, 0), tree_sum(200005, 0);

long long _Sum(vector<long long>& tree, int value)
{
	long long ret = 0;
	int i = value;
	while (i)
	{
		ret += tree[i];
		i -= (i & -i);
	}
	return ret;
}

long long Sum(vector<long long>& tree, int s, int e)
{
	if (s > e)
	{
		return 0;
	}
	return(_Sum(tree, e) - _Sum(tree, s - 1));
}

void Update(vector<long long>& tree, int x, long long value)
{
	int i = x;
	while (i <= 200004)
	{
		tree[i] += value;
		i += (i & -i);
	}
	return;
}

int main()
{
	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		cin >> value;
		value++;
		if (i != 1)
		{
			long long left = value * Sum(tree_cnt , 1, value -1) - Sum(tree_sum,1,value - 1);
			long long right = Sum(tree_sum, value + 1, 200004) - value * Sum(tree_cnt, value + 1, 200004);

			result *= (left + right) % MOD;
			result %= MOD;
		}
		Update(tree_cnt, value, 1);
		Update(tree_sum, value, value);
	}
	cout << result;
}	