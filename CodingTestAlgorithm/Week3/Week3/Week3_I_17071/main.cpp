#include <bits/stdc++.h>

using namespace std;
int N, K;
int visited[2][500004];
int turn = 1;
int check;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> K;

	if (N == K)
	{
		cout << 0 << "\n";
		return 0;
	}
	queue<int> q;
	visited[0][N] = 1;
	q.push(N);
	while (q.size())
	{
		K += turn;
		if (K > 500000)break;
		if (visited[turn % 2][K]) {
			check = true;
			break;
		}
		int qSize = q.size();
		for (int i = 0; i < qSize; i++) {
			int x = q.front(); q.pop();
			for (int nx : {x + 1, x - 1, x * 2}) {
				if (nx < 0 || nx > 500000 || visited[turn % 2][nx]) continue;
				visited[turn % 2][nx] = visited[(turn + 1) % 2][x] + 1;
				if (nx == K) {
					check = 1; break;
				}
				q.push(nx);
			}
			if (check)break;
		}
		if (check)break;
		turn++;
	}

	if (check) cout << turn << "\n";
	else cout << -1 << "\n";
	return 0;
}