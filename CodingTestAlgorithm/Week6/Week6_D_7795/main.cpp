#include <bits/stdc++.h>

using namespace std;
int T, N, M;

int main()
{
	cin >> T;
	for (int i = 0; i < T; i++)
	{
		vector<int> a(N);
		vector<int>b(M);
		int result{};
		cin >> N >> M;
		for (int i = 0; i < N; i++)
		{
			cin >> a[i];
		}
		for (int i = 0; i < M; i++)
		{
			cin >> b[i];
		}
		sort(a.begin(), a.end());
		sort(b.begin(),b.end());
		for (int i = 0; i < N; i++)
		{
			auto pos = lower_bound(b.begin(), b.end(), a[i]);
			result += (int)(pos - b.begin());
		}
		cout << result<<'\n';
	}
}