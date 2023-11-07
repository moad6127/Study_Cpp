#include <bits/stdc++.h>

using namespace std;
int N,A,B,NOW;
vector<pair<int, int>> a;
int result;
int main()
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> A >> B;
		a.push_back({ B,A });
	}
	sort(a.begin(), a.end());

	for (auto e : a)
	{
		if (NOW <= e.second)
		{
			result++;
			NOW = e.first;
		}
	}
	cout << result;

}