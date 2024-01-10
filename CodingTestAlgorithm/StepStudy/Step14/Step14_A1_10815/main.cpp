#include <bits/stdc++.h>

using namespace std;

int N, M;
map<int, int> L;

int main()
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int temp{};
		cin >> temp;
		L[temp]++;
	}
	cin >> M;
	for (int i = 0; i < M; i++)
	{
		int temp{};
		cin >> temp;
		cout << L[temp] << " ";
	}
}