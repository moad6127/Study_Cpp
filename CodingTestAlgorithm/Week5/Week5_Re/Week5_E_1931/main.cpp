#include <bits/stdc++.h>

using namespace std;

int n, a, b, result, realTime;
vector<pair<int, int>> v;
int main()
{
	cin >> n;
	for (int i = 0;i < n;i++)
	{
		cin >> a >> b;
		v.push_back({ b, a });
	}
	//끝나는 시간으로 정렬
	sort(v.begin(), v.end());
	realTime = v[0].first;
	result += 1;
	for (int i = 1; i < n;i++)
	{
		if (realTime <= v[i].second)
		{
			realTime = v[i].first;
			result++;
		}
	}

	cout << result;
}