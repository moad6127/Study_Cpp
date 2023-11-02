#include<bits/stdc++.h>

using namespace std;

int N,A,B;
int result;
vector<pair<int, int>>a;
int main()
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> A >> B;
		a.push_back({ A,B });
	}
	sort(a.begin(), a.end());
	result = a[0].first + a[0].second;
	for (int i = 1; i < a.size(); i++)
	{
		result = max(result, a[i].first);
		result += a[i].second;
	}
	cout << result;
}