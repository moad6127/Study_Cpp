#include <bits/stdc++.h>

using namespace std;

int n, mp, mf, ms, mv; //�ķ�ǰ ����, �ּ� ��,��,ź,��
int result = 987654321;
struct Info {
	int p; // ��
	int f; // ��
	int s; // ź
	int v; // ��
	int c; // ����
};

Info a[20];
map<int, vector<vector<int>>> ret_V;
int main()
{
	cin >> n >> mp >> mf >> ms >> mv;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i].p >> a[i].f >> a[i].s >> a[i].v >> a[i].c;
	}
	for (int i = 1; i < (1 << n); i++)
	{
		int b{};
		int c{};
		int d{};
		int e{};
		int sum{};
		vector<int> v;
		for (int j = 0; j < n; j++)
		{
			if (i & (1 << j))
			{
				v.push_back(j + 1);
				b += a[j].p;
				c += a[j].f;
				d += a[j].s;
				e += a[j].v;
				sum += a[j].c;
			}
		}
		if (b >= mp && c >= mf && d >= ms && e >= mv)
		{
			if (result >= sum)
			{
				result = sum;
				ret_V[result].push_back(v);
			}
		}
	}

	if (result == 987654321)
	{
		cout << -1 << '\n';
	}
	else
	{
		sort(ret_V[result].begin(), ret_V[result].end());
		cout << result << '\n';
		for (int e : ret_V[result][0])
		{
			cout << e << " ";

		}
	}
}