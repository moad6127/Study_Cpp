#include <bits/stdc++.h>

using namespace std;
int N, K;
int A, B;
long long result;
int main()
{
	cin >> N >> K;
	vector<pair<int, int>> v1(N);
	vector<int> v2(K);
	for (int i = 0; i < N; i++)
	{
		cin >> A >> B;
		v1[i].first = A;
		v1[i].second = B;
	}
	for (int i = 0; i < K; i++)
	{
		cin >> A;
		v2[i] = A;
	}
	sort(v1.begin(), v1.end());
	sort(v2.begin(), v2.end());

	priority_queue<int> pq;

	int j = 0;
	for (int i = 0; i < K; i++)
	{
		while (j < N && v1[j].first <= v2[i])
		{
			pq.push(v1[j++].second);
		}
		if (pq.size())
		{
			result += pq.top();
			pq.pop();
		}
	}
	cout << result;
}