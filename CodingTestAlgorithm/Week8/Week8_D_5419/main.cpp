#include <bits/stdc++.h>

using namespace std;

int T, N, x,y;
vector<int> tree, _y;
vector<pair<int, int>> a;

int Sum(int idx)
{
	int result{};
	while (idx > 0)
	{
		result += tree[idx];
		idx -= (idx & -idx);
	}
	return result;
}

void Update(int pos, int v)
{
	int idx = pos;
	while (idx <= N)
	{
		tree[idx] += v;
		idx += (idx & -idx);
	}
}
int FindIdx(const vector<int>& _y, int v)
{
	int lo{};
	int hi = _y.size() - 1;
	while (lo <= hi)
	{
		int mid = (lo + hi) / 2;
		if (_y[mid] == v)
		{
			return mid;
		}
		if (_y[mid] < v)
		{
			lo = mid + 1;
		}
		else
		{
			hi = mid - 1;
		}
	}
}
int main()
{
	cin >> T;
	for (int t = 0; t < T; t++)
	{
		cin >> N;
		tree.clear();
		tree.resize(N + 1);
		a.clear();
		_y.clear();
		for (int i = 0; i < N; i++)
		{
			cin >> x >> y;
			a.push_back({ x, y * -1 });
			_y.push_back(y * -1);
		}
		sort(a.begin(), a.end());
		sort(_y.begin(), _y.end());
		long long result = 0;

		Update(FindIdx(_y, a[0].second) + 1, 1);
		for (int i = 1; i < N; i++)
		{
			int idx = FindIdx(_y, a[i].second) + 1;
			result += (long long)1 * Sum(idx);
			Update(idx, 1);
		}

		cout << result<<'\n';
	}

}