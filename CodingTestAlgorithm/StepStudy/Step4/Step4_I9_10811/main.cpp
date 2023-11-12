#include <bits/stdc++.h>

using namespace std;

int N,M;
int A, B;
vector<int> a;
int main()
{
	cin >> N >> M;
	for (int i = 1; i <= N; i++)
	{
		a.push_back(i);
	}
	for (int i = 0; i < M; i++)
	{

		cin >> A >> B;
		reverse(a.begin() + A - 1, a.begin() + B );
	}

	for (int i = 0; i < N; i++)
	{
		cout << a[i] << " ";
	}
}