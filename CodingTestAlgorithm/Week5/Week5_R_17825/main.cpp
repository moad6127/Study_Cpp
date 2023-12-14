#include <bits/stdc++.h>

using namespace std;

int a[11], c[4];
int v[104]{ 0,2,4,6,8,10,12,14,16,18,20,22,24,26,28,30,32,34,36,38,40,13,16,19,25,30,35,22,24,28,27,26 };
vector<int> adj[54];

int Move(int here, int cnt)
{
	if (here == 100)
	{
		return 100;
	}
	if (adj[here].size() >= 2)
	{
		here = adj[here][1];
		cnt--;
	}
	if (cnt) {
		queue<int>q;
		q.push(here);
		int there;
		while (q.size()) {
			int x = q.front(); q.pop();
			there = adj[x][0];
			q.push(there);
			if (there == 100)break;
			cnt--;
			if (cnt == 0)break;
		}
		return there;
	}
	else
	{
		return here;
	}
}
bool Check(int mal_idx,int idx)
{
	if (mal_idx == 100)
	{
		return false;
	}
	for (int i = 0; i < 4; i++)
	{
		if (i == idx)
		{
			continue;
		}
		if (c[i] == mal_idx)
		{
			return true;
		}
	}
	return false;
}

void Add(int here, int there)
{
	adj[here].push_back(there);
}
void Map()
{
	for (int i = 0; i <= 19; i++)
	{
		Add(i, i + 1);
	}
	Add(5, 21);
	Add(21, 22);
	Add(22, 23);
	Add(23, 24);
	Add(15, 29);
	Add(29, 30);
	Add(30, 31);
	Add(31, 24);
	Add(10, 27);
	Add(27, 28);
	Add(28, 24);
	Add(24, 25);
	Add(25, 26);
	Add(26, 20);
	Add(20, 100);
}

int go(int here)
{
	if (here == 10)
	{
		return 0;
	}
	int result = 0;
	for (int i = 0; i < 4; i++)
	{
		int temp_idx = c[i];
		int mal_idx = Move(temp_idx, a[here]);
		if (Check(mal_idx, i))
		{
			continue;
		}
		c[i] = mal_idx;
		result = max(result, go(here + 1) + v[mal_idx]);
		c[i] = temp_idx;
	}

	return result;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	Map();
	for (int i = 0; i < 10; i++)
	{
		cin >> a[i];
	}

	cout << go(0);
}