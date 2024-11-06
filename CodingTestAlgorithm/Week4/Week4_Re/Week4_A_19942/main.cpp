#include <bits/stdc++.h>

using namespace std;

int n, mp, mf, ms, mv; //식료품 개수, 최소 단,지,탄,비
int result = 987654321;
struct Info {
	int p; // 단
	int f; // 지
	int s; // 탄
	int v; // 비
	int c; // 가격
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