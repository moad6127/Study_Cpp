#include <bits/stdc++.h>

using namespace std;

int n, c, x;
int a[14], comp[14],visited[14];
vector<int> v[14];
int result = 987654321;

pair<int, int> dfs(int here, int value)
{
	visited[here] = 1;
	pair<int, int> ret{1, a[here]};
	for (int there : v[here])
	{
		if (comp[there] != value)
		{
			continue;
		}
		if (visited[there])
		{
			continue;
		}
		pair<int, int> _temp = dfs(there, value);
		ret.first += _temp.first;
		ret.second += _temp.second;
	}
	return ret;
}
int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++)
	{
		cin >> c;
		for (int j = 0; j < c; j++)
		{
			cin >> x;
			v[i].push_back(x);
			v[x].push_back(i);
		}
	}
	// 비트마스킹으로 완전탐색 1 ~ 끝까지
	// ispossible로 가능 불가능 체크
	//가능하면 최소값 구하기

	for (int i = 1; i < (1 << n) - 1; i++)
	{
		fill(visited, visited + 14, 0);
		fill(comp, comp + 14, 0);
		int idx1 = -1;
		int idx2 = -1;
		for (int j = 0; j < n; j++)
		{
			if (i & (1 << j))
			{
				comp[j + 1] = 1;
				idx1 = j + 1;
			}
			else
			{
				idx2 = j + 1;
			}
		}
		pair<int, int> comp1 = dfs(idx1, 1);
		pair<int, int> comp2 = dfs(idx2, 0);
		if (comp1.first + comp2.first == n)
		{
			result = min(result, abs(comp1.second - comp2.second));
		}
	}
	if (result == 987654321)
	{
		cout << -1;
	}
	else
	{
		cout << result;
	}

	return 0;
}
//
//#include <iostream>
//#include <vector>
//#include <queue>
//#include <cmath>
//#include <algorithm>
//
//using namespace std;
//
//int N;
//vector<int> population;
//vector<vector<int>> adj;
//vector<bool> visited;
//
//bool isConnected(const vector<int>& district) {
//    fill(visited.begin(), visited.end(), false);
//    queue<int> q;
//    q.push(district[0]);
//    visited[district[0]] = true;
//    int count = 1;
//
//    while (!q.empty()) {
//        int node = q.front();
//        q.pop();
//        for (int neighbor : adj[node]) {
//            if (!visited[neighbor] && find(district.begin(), district.end(), neighbor) != district.end()) {
//                visited[neighbor] = true;
//                q.push(neighbor);
//                count++;
//            }
//        }
//    }
//    return count == district.size();
//}
//
//int main() {
//    cin >> N;
//    population.resize(N);
//    adj.resize(N);
//    visited.resize(N);
//
//    for (int i = 0; i < N; i++) {
//        cin >> population[i];
//    }
//
//    for (int i = 0; i < N; i++) {
//        int num_neighbors;
//        cin >> num_neighbors;
//        adj[i].resize(num_neighbors);
//        for (int j = 0; j < num_neighbors; j++) {
//            cin >> adj[i][j];
//            adj[i][j]--; // 0-based indexing
//        }
//    }
//
//    int min_diff = INT_MAX;
//    for (int i = 1; i < (1 << N) - 1; i++) {
//        vector<int> district1, district2;
//        for (int j = 0; j < N; j++) {
//            if (i & (1 << j)) district1.push_back(j);
//            else district2.push_back(j);
//        }
//        if (isConnected(district1) && isConnected(district2)) {
//            int pop1 = 0, pop2 = 0;
//            for (int d : district1) pop1 += population[d];
//            for (int d : district2) pop2 += population[d];
//            min_diff = min(min_diff, abs(pop1 - pop2));
//        }
//    }
//
//    if (min_diff == INT_MAX) cout << -1 << endl;
//    else cout << min_diff << endl;
//
//    return 0;
//}
