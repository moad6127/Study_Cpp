#include <bits/stdc++.h>

using namespace std;

int n;
int a[1001], result = 1, cnt[1001], idx;
int pr[1001];

void out(int idx)
{
	if (idx == -1)
	{
		return;
	}
	out(pr[idx]);
	cout << a[idx] << " ";
}
int main()
{
	cin >> n;
	for (int i = 0;i < n;i++)
	{
		cin >> a[i];
	}
	fill(pr, pr + 1001, -1);
	fill(cnt, cnt + 1001, 1);
	for (int i = 0;i < n;i++)
	{
		for (int j = 0; j < i;j++)
		{
			if (a[j] < a[i] && cnt[i] < cnt[j] + 1)
			{
				cnt[i] = cnt[j] + 1;
				pr[i] = j;
				if (result < cnt[i])
				{
					result = cnt[i];
					idx = i;
				}
			}
		}
	}
	cout << result << '\n';
	out(idx);
}