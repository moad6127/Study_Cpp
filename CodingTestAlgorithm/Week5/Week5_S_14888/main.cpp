#include <bits/stdc++.h>

using namespace std;
int N, minNum = 1000000001, maxNum = -1000000001;
vector<int> a;
const string CHECK = { "+-*/" };
vector<char> v;
int Oper(int a, int b, char op)
{
	if (op == '+')
	{
		return a + b;
	}
	else if (op == '-')
	{
		return a - b;
	}
	else if (op == '*')
	{
		return a * b;
	}
	else
	{
		return a / b;
	}
}
void Func(vector<char>& v)
{
	int sum{a[0]};
	for (int i = 0; i < v.size(); i++)
	{
		sum = Oper(sum, a[i + 1], v[i]);
	}
	minNum = min(minNum, sum);
	maxNum = max(maxNum, sum);
}

int main()
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int temp{};
		cin >> temp;
		a.push_back(temp);
	}
	for (int i = 0; i < 4; i++)
	{
		int temp{};
		cin >> temp;
		for (int j = 0; j < temp; j++)
		{
			v.push_back(CHECK[i]);
		}
	}
	sort(v.begin(), v.end());
	do
	{
		Func(v);
	} while (next_permutation(v.begin(), v.end()));

	cout << maxNum << '\n' << minNum << '\n';
}