#include <bits/stdc++.h>

using namespace std;

int n, fNode, temp, RNode, ans;
vector<int> adj[51];

int Func(int node)
{
	int result{};
	int chi{};
	if (adj[node].empty())
	{
		return 1;
	}
	for (auto e : adj[node])
	{
		if(e == RNode)
		{
			continue;
		}
		result += Func(e);
		chi++;
	}
	if (chi == 0)
	{
		return 1;
	}
	return result;
}
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> temp;
		if (temp == -1)
		{
			fNode = i;
			continue;
		}
		adj[temp].push_back(i);
	}
	cin >> RNode;
	if (RNode == fNode)
	{
		cout << 0;
	}
	else
	{
		cout << Func(fNode);
	}

}