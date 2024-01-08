#include <bits/stdc++.h>

using namespace std;

int N;
vector<int> v1;
vector<int> v2;

int main()
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int temp{};
		cin >> temp;
		v1.push_back(temp);
		v2.push_back(temp);
	}
	sort(v1.begin(), v1.end());
	v1.erase(unique(v1.begin(), v1.end()), v1.end());
	for (int i = 0; i < N; i++)
	{
		cout << lower_bound(v1.begin(), v1.end(), v2[i]) - v1.begin() << ' ';
	}
}