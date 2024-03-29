#include <bits/stdc++.h>

using namespace std;

int T, N, M,temp;
int check(int temp, vector<int>& v)
{
	int l = 0;
	int r = v.size() - 1;
	int mid{};
	while (l <= r)
	{
		mid = (l + r) / 2;
		if (v[mid] > temp)
		{
			r = mid - 1;
		}
		else if (v[mid] == temp)
		{
			return 1;
		}
		else
		{
			l = mid + 1;
		}
	}
	return 0;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> T;
	for (int i = 0; i < T; i++)
	{
		vector<int> v;
		cin >> N;
		
		for (int j = 0; j < N; j++)
		{
			cin >> temp;
			v.push_back(temp);
		}
		sort(v.begin(), v.end());
		cin >> M;
		for (int j = 0; j < M; j++)
		{
			cin >> temp;
			cout << check(temp, v) << '\n';
		}
	}
}