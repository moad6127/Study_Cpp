#include <bits/stdc++.h>

using namespace std;

int T, n, m;
int tree[200005], temp;
map<int, int> mp;

void Update(int idx, int val)
{
	while (idx <= 200004)
	{
		tree[idx] += val;
		idx += (idx & -idx);
	}
}
int Sum(int idx)
{
	int ret = 0;
	while (idx > 0) {
		ret += tree[idx];
		idx -= (idx & -idx);
	}
	return ret;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> T;
	for (int i = 0; i < T; i++)
	{
		cin >> n >> m;
		memset(tree, 0, sizeof(tree));
		mp.clear();
		int update_idx = 100001;
		for (int j = 1; j <= n; j++)
		{
			Update(j + update_idx, 1);
			mp[j] = j + update_idx;
		}
		for (int j = 0; j < m; j++)
		{
			cin >> temp;
			int idx = mp[temp];
			cout << Sum(idx) - 1 << " ";
			Update(idx, -1);
			Update(--update_idx, 1);
			mp[temp] = update_idx;
		}
		cout << '\n';
	}
}