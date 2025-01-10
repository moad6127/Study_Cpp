#include <bits/stdc++.h>

using namespace std;

int n, result;
bool pri[4000001];

vector<int> era(int mx_n) {
	vector<int> v;
	for (int i = 2; i <= mx_n; i++) {
		if (pri[i]) continue;
		for (int j = 2 * i; j <= mx_n; j += i) {
			pri[j] = 1;
		}
	}
	for (int i = 2; i <= mx_n; i++) if (pri[i] == 0)v.push_back(i);
	return v;
}

int main()
{
	cin >> n;
	vector<int> vv = era(n);
	for (int start = 0; start < vv.size();start++)
	{
		int sum{vv[start]};
		int j{start + 1};
		while (true)
		{
			if (sum > n)
			{
				break;
			}
			if (sum == n)
			{
				result++;
				break;
			}
			if(j >= vv.size())
			{
				break;
			}
			sum += vv[j++];
		}
	}

	cout << result;
}