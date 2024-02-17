#include <bits/stdc++.h>

using namespace std;
int N,result = 1;
int a[1004], cnt[1004],idx,pr[1004];
void Print(int idx)
{
	if (idx == -1)
	{
		return;
	}
	Print(pr[idx]);
	cout << a[idx] << " ";
}
int main()
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> a[i];
	}
	fill(pr, pr + 1004, -1);
	fill(cnt, cnt + 1004, 1);
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < i; j++)
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
	Print(idx);
}