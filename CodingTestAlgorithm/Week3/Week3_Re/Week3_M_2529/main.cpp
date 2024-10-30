#include <bits/stdc++.h>

using namespace std;
int n;
char a[10];
string resultMin{ "987654321" };
string resultMax{ "-1"};
int visited[10];

bool CheckA(char a, char b, char op)
{
	if (op == '<')
	{
		return a < b;
	}
	return a > b;
}

bool Check(string s, int size)
{
	for (int i = 0; i < size; i++)
	{
		if (!CheckA(s[i], s[i + 1], a[i]))
		{
			return false;
		}
	}
	return true;
}

void dfs(string s, int here)
{
	if (s.size() == n + 1)
	{
		if (Check(s, n))
		{
			resultMax = max(resultMax, s);
			resultMin = min(resultMin, s);
		}
		return;
	}
	if (!Check(s, here))
	{
		return;
	}
	for (int a = 0 ; a<10;a++)
	{
		if (visited[a])
		{
			continue;
		}
		s.push_back(a + '0');
		visited[a] = 1;
		dfs(s, here + 1);
		s.pop_back();
		visited[a] = 0;
	}
}
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	string s;
	dfs(s,-1);
	cout << resultMax << '\n';
	cout << resultMin << '\n';
}