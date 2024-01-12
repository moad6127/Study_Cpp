#include <bits/stdc++.h>

using namespace std;

int N, M, result;
unordered_set<string> s;
int main()
{
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		string temp;
		cin >> temp;
		s.insert(temp);
	}
	for (int i = 0; i < M; i++)
	{
		string temp;
		cin >> temp;
		if (s.find(temp) != s.end())
		{
			result++;
		}
	}
	cout << result;
}