#include <bits/stdc++.h>
using namespace std;

int K;
char a[12];
vector<string> result;
int visited[10];

bool compChek(char a, char b, char op)
{
	if (op == '<')
	{
		return a < b;
	}
	else
	{
		return a > b;
	}
}
void Func(int idx ,string num)
{
	if (num.size() == K + 1)
	{
		result.push_back(num);
		return;
	}

	for (int i = 0; i <= 9; i++)
	{
		if (visited[i])
		{
			continue;
		}
		if (idx == 0 || compChek(num[idx - 1], i + '0', a[idx - 1]))
		{
			visited[i] = 1;
			Func(idx + 1, num + to_string(i));
			visited[i] = 0;
		}
	}
}


int main()
{
	cin >> K;
	for (int i = 0; i < K; i++)
	{
		cin >> a[i];
	}
	Func(0, "");
	sort(result.begin(), result.end());
	cout << result.back() << '\n' << result[0];
}