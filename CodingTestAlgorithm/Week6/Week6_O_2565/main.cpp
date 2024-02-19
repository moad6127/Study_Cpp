#include <bits/stdc++.h>

using namespace std;

int N, lis[104],len;
pair<int, int> a[104];
int main()
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> a[i].first >> a[i].second;
	}
	sort(a, a + N);

	for (int i = 0; i < N; i++)
	{
		auto it = lower_bound(lis, lis + len, a[i].second);
		if (*it == 0)
		{
			len++;
		}
		*it = a[i].second;
	}
	cout << N - len;
}