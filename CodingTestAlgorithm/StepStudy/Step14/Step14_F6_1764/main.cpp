#include <bits/stdc++.h>

using namespace std;

int N, M;
map<string, int> m;
string s;
vector<string> result;
int main()
{
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		cin >> s;
		m[s]++;
	}
	for (int i = 0; i < M; i++)
	{
		cin >> s;
		m[s]++;
		if (m[s] > 1)
		{
			result.push_back(s);
		}
	}
	cout << result.size() << '\n';
	sort(result.begin(), result.end());
	for (auto e : result)
	{
		cout << e << '\n';
	}
}