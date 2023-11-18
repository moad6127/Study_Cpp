#include <bits/stdc++.h>

using namespace std;

int N, K, result;
int a[104],visited[104];
vector<int> v;
int main()
{
	cin >> N >> K;
	for (int i = 0; i < K; i++)
	{
		cin >> a[i];
	}
	for (int i = 0; i < K; i++)
	{
		if (!visited[a[i]])
		{
			if (v.size() == N)
			{
				int lastIdx{}, pos{};
				for (int _a : v)
				{
					int here = 10000000;
					for (int j = i + 1; j < K; j++)
					{
						if (_a == a[j])
						{
							here = j;
							break;
						}
					}
					if (lastIdx < here)
					{
						lastIdx = here;
						pos = _a;
					}
				}
				visited[pos] = 0;
				result++;
				v.erase(find(v.begin(), v.end(), pos));
			}
			v.push_back(a[i]);
			visited[a[i]] = 1;
		}
	}
	cout << result;
}