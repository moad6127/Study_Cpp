#include <bits/stdc++.h>

using namespace std;
long long a[31];
long long N, C, result;
vector<int> v1, v2;

void Func(int here, int size,vector<int>& v, int num)
{
	if (num > C)
	{
		return;
	}
	if (here > size)
	{
		v.push_back(num);
		return;
	}

	Func(here + 1,size,v, num);
	Func(here + 1,size,v, num + a[here]);

	return;
}

int main()
{
	cin >> N >> C;
	for (int i = 0; i < N; i++)
	{
		cin >> a[i];
	}
	Func(0, N / 2 - 1, v1, 0);
	Func(N / 2, N - 1, v2, 0);
	sort(v1.begin(), v1.end());
	sort(v2.begin(), v2.end());
	for (auto e : v1)
	{
		if (C - e >= 0)
		{
			result += upper_bound(v2.begin(), v2.end(), C - e) - v2.begin();
		}
	}
	cout << result;
}
