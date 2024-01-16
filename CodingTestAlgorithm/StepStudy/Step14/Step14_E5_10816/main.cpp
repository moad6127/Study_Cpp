#include <bits/stdc++.h>

using namespace std;

int N, M, a;
map<int, int> m;
int main()
{

	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> a;
		m[a]++;
	}
	cin >> M;
	for (int i = 0; i < M; i++)
	{
		cin >> a;
		cout << m[a] << " ";
	}

}