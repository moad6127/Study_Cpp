#include <bits/stdc++.h>

using namespace std;

int N;
vector<int> v;
int main()
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int temp{};
		cin >> temp;
		v.push_back(temp);
	}
	sort(v.begin(), v.end());
	for (auto e : v)
	{
		cout << e << '\n';
	}
}