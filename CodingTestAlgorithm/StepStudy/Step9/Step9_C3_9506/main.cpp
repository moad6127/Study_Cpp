#include <bits/stdc++.h>

using namespace std;

int N;

vector<int> Func(int N)
{
	int sum{};
	vector<int> v;
	for (int i = 1; i <N; i++)
	{
		if (N % i == 0)
		{
			sum += i;
			v.push_back(i);
		}
	}
	if (sum == N)
	{
		return v;
	}
	return vector<int>();
}
void Print(vector<int>& v)
{
	if (v.size())
	{
		cout << N << " = ";
		for (int i = 0; i < v.size() - 1; i++)
		{
			cout << v[i] << " + ";
		}
		cout << v.back() << '\n';
	}
	else
	{
		cout << N << " is NOT perfect." << '\n';
	}
}
int main()
{
	while (true)
	{
		cin >> N;
		if (N == -1)
		{
			break;
		}
		vector<int> temp;
		temp = Func(N);
		Print(temp);
	}
}