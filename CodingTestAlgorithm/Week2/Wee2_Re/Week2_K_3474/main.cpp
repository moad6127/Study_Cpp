#include <bits/stdc++.h>

using namespace std;
int t, n;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> t;
	for (int i = 0; i < t; i++)
	{
		cin >> n;
		int result{};
		for (int j = 5; j <= n; j *= 5)
		{
			result += n / j;
		}
		cout << result<<'\n';
	}
}