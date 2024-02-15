#include <bits/stdc++.h>

using namespace std;

int N;
int a[1004], result, cnt[1004];
int main()
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> a[i];
	}
	for (int i = 0; i < N; i++)
	{
		int mx = 0;
		for (int j = 0; j < i; j++)
		{
			if (a[j] < a[i] && mx < cnt[j])
			{
				mx = cnt[j];
			}
		}
		cnt[i] = mx + 1;
		result = max(result, cnt[i]);
	}
	cout << result;
}