//
//
// 
// 
// 8주차 알고리즘 공부 펜윅트리, 최단거리
// 
// 
// 펜윅트리
// 
// 이진트리 기반의 자료구조이며 세그먼트 트리의 원리를 가지고 있다.
// 
// 세그먼트 트리란?
// 
// 이진트리중에 어떤 쿼리에 대해 최적화한 값을 담아두는것을 말한다.
// 
// 펜윅트리는 이러한 특징이 담겨있다/
// 
// 펜윅 트리는 최하위 노드를 갱신하며 업데이트 하는 트리를 말한다.
// 세그먼트와 다르게 모든 세그먼트를 만들 필요가 없는 효율적으로 계산하는 트리이다.
// 
// 백준 2042 구간합 문제
//
//#include <bits/stdc++.h>
//using namespace std;
//int n, m, k, t1, t2, t3;
//long long t4;
//long long sum(vector<long long>& tree, int i) {
//    long long ans = 0;
//    while (i > 0) {
//        ans += tree[i];
//        i -= (i & -i);
//    }
//    return ans;
//}
//void update(vector<long long>& tree, int i, long long diff) {
//    while (i < tree.size()) {
//        tree[i] += diff;
//        i += (i & -i);
//    }
//}
//int main() {
//    scanf("%d %d %d", &n, &m, &k);
//    vector<long long> a(n + 1);
//    vector<long long> tree(n + 1);
//    for (int i = 1; i <= n; i++) {
//        scanf("%lld", &a[i]);
//        update(tree, i, a[i]);
//    }
//    m += k;
//    while (m--) {
//        scanf("%d", &t1);
//        if (t1 == 1) {
//            scanf("%d %lld", &t2, &t4);
//            long long diff = t4 - a[t2];
//            a[t2] = t4;
//            update(tree, t2, diff);
//        }
//        else {
//            int t2, t3;
//            scanf("%d %d", &t2, &t3);
//            printf("%lld\n", sum(tree, t3) - sum(tree, t2 - 1));
//        }
//    }
//    return 0;
//}
//[출처] [알고리즘 강의] 8주차.펜윅트리와 최단거리알고리즘(다익스트라, 플로이드워셜, 벨만포드) | 작성자 큰돌
//
// 
// 이때 문제를 보면
// 입력을 받을때 1번 인덱스부터 받기 시작한다.
// 
// 
// 백준 3653 영화수집 문제
// 
// #include<bits/stdc++.h>
//using namespace std;
//int t, n, m, tree[200004], temp;
//map<int, int> mp;
//void update(int idx, int value) {
//    while (idx <= 200004) {
//        tree[idx] += value;
//        idx += (idx & -idx);
//    }
//}
//int sum(int idx) {
//    int ret = 0;
//    while (idx > 0) {
//        ret += tree[idx];
//        idx -= (idx & -idx);
//    }
//    return ret;
//}
//int main() {
//    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
//    cin >> t;
//    while (t--) {
//        cin >> n >> m;
//        memset(tree, 0, sizeof(tree));
//        mp.clear();
//        int update_idx = 100001;
//        for (int i = 1; i <= n; i++) {
//            update(i + update_idx, 1);
//            mp[i] = i + update_idx;
//        }
//        for (int i = 0; i < m; i++) {
//            cin >> temp;
//            int idx = mp[temp];
//            cout << sum(idx) - 1 << " ";
//            update(idx, -1);
//            update(--update_idx, 1);
//            mp[temp] = update_idx;
//        }
//        cout << "\n";
//    }
//}
//[출처] [알고리즘 강의] 8주차.펜윅트리와 최단거리알고리즘(다익스트라, 플로이드워셜, 벨만포드) | 작성자 큰돌
//
// 
// 
// 
// 
// 최단거리 알고리즘
// 
// BFS같은 경우의 알고리즘은 가중치가 같을경우 사용할수 있지만, 가중치가 다를경우
// 이러한 최단거리 알고리즘을 사용해서 풀이한다.
// 
// 다익스트라 알고리즘
// 
// 음의 가중치가 없는 그래프에서 사용할수 있다.
// 
// 우선순위큐에 PQ에 있는 정점에서 해당정점까지의 거리가 가장낮은 정점을 중심으로 거리배열을 갱신하며
// 다시 큐에 넣는 행위를 반복하여 최종적으로 거리배열을 완성하는 알고리즘이다.
// 
// 정점 v까지 거리와 비교해서 더짧은 경우에 갱신을 한다.
// dist[u] + w[u,v] = dist[v]로 갱신한다.
// 
// 
// 
// 백준 1753 최단경로문제
// 
// #include <cstdio> 
//#include <algorithm> 
//#include <vector>
//#include <queue>
//using namespace std;
//int V, E, K, u, v, w;
//vector<pair<int, int>> adj[20001];
//int dist[20001];
//bool visited[20001];
//const int INF = 987654321;
//priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
//int main() {
//	scanf("%d %d %d", &V, &E, &K);
//	fill(dist, dist + 20001, INF);
//	for (int i = 0; i < E; i++) {
//		scanf("%d %d %d", &u, &v, &w);
//		adj[u].push_back(make_pair(w, v));
//	}
//	pq.push(make_pair(0, K));
//	dist[K] = 0;
//	while (pq.size()) {
//		int here = pq.top().second;
//		int here_dist = pq.top().first;
//		pq.pop();
//		if (dist[here] != here_dist) continue;
//		for (pair<int, int> there : adj[here]) {
//			int _dist = there.first;
//			int _there = there.second;
//			if (dist[_there] > dist[here] + _dist) {
//				dist[_there] = dist[here] + _dist;
//				pq.push(make_pair(dist[_there], _there));
//			}
//		}
//	}
//	for (int i = 1; i <= V; i++) {
//		if (dist[i] == INF) puts("INF");
//		else printf("%d\n", dist[i]);
//	}
//	return 0;
//}
//[출처] [알고리즘 강의] 8주차.펜윅트리와 최단거리알고리즘(다익스트라, 플로이드워셜, 벨만포드) | 작성자 큰돌
//
// dist를 최대치로 정해둔다.
// 
// 
// 
// 플로이도워셜 알고리즘
// 
// 모든 쌍 최단거리 알고리즘입니다. 
// u에서 v로 가는데 경유점을 거치는게 더 빠르다면 완화를 시켜 거리배열을 갱신시켜 나가는 것입니다.
// 이 플로이드 워셜은 모든 쌍 최단거리경로를 구하기도 하고
//  i, j가 간접적, 직간접적으로 연결되어있는지도 확인할 수 있습니다.
//  또한 그래프의 지름을 구할 수도 있습니다. 하지만 시간복잡도가 상당하죠?
//  V의 3제곱입니다. 따라서 이 알고리즘은 문제에서 N 의 크기가 어느정도 작을 때 쓸 수 있습니다.
//
// 
// 백준	11404 문제
// 
// #include <cstdio>
//#include <algorithm>
//#include <iostream>
//int n, m, a, b, c, dist[104][104];
//const int INF = 987654321;
//using namespace std;
//int main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//	cout.tie(NULL);
//	cin >> n >> m;
//	fill(&dist[0][0], &dist[0][0] + 104 * 104, INF);
//	for (int i = 0; i < m; i++) {
//		cin >> a >> b >> c;
//		a--; b--;
//		dist[a][b] = dist[a][b] ? min(dist[a][b], c) : c;
//	}
//	for (int k = 0; k < n; k++)
//		for (int i = 0; i < n; i++)
//			for (int j = 0; j < n; j++)
//				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
//	for (int i = 0; i < n; i++) {
//		for (int j = 0; j < n; j++)
//			if (i == j)printf("0 ");
//			else printf("%d ", dist[i][j] == INF ? 0 : dist[i][j]);
//		puts("");
//	}
//	return 0;
//}
//[출처] [알고리즘 강의] 8주차.펜윅트리와 최단거리알고리즘(다익스트라, 플로이드워셜, 벨만포드) | 작성자 큰돌
//
//
// 최종적으로 dist[i][j]를 만드는 알고리즘으로 
// k,i,j의 순서를 기억 해두고 2차원 배열을 갱신하면서 i에서 j까지 가는 최단거리를 구하는 알고리즘이다.
// 
// 
// 
// 벨만 포트 알고리즘
// 
// 음의 가중치가 있는 그래프의 경우 사용하는 최단거리 알고리즘
// 다익스트라와 달리 음의 가중치가 존재할경우 사용하는 알고리즘이다.
// 
// 타임머신, 블랙홀 같은 이전상태로 돌아갈새 사용하는 알고리즘이다.
// 
// 
// 백준 11657 타임머신 문제
// #include<bits/stdc++.h>
//using namespace std;
//long long t, n, m, a, b, c, dist[1004], INF = 987654321, visited[1004];
//int main() {
//    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
//    t = 1;
//    for (int T = 1; T <= t; T++) {
//        cin >> n >> m;
//        fill(dist, dist + n + 1, INF);
//        vector<pair<int, int>> adj[1004];
//        for (int i = 0; i < m; i++) {
//            cin >> a >> b >> c;
//            adj[a - 1].push_back({ b - 1, c });
//        }
//        dist[0] = 0; queue<int> q;
//        for (int i = 0; i < n; i++) {
//            for (int here = 0; here < n; here++) {
//                for (auto there : adj[here]) {
//                    int d = there.second;
//                    int to = there.first;
//                    if (dist[here] != INF && dist[here] + d < dist[to]) {
//                        if (i == n - 1)q.push(to);
//                        dist[to] = dist[here] + d;
//                    }
//                }
//            }
//        }
//        if (q.size()) cout << -1 << "\n";
//        else for (int i = 1; i < n; i++) cout << (dist[i] == INF ? -1 : dist[i]) << "\n";
//    }
//}
//[출처] [알고리즘 강의] 8주차.펜윅트리와 최단거리알고리즘(다익스트라, 플로이드워셜, 벨만포드) | 작성자 큰돌
//
//
// 이러한 3가지의 최단거리알고리즘이 존재하며 어떤상황일때 사용하면 좋은지 알아야 한다.
// 
// 다익스트라 알고리즘은 시점점부터 끝점이 존재할때 사용하며 N의 크기가 크고
// 음의 가중치가 존재하지 않을경우 사용한다.
// 
// 플로이드 알고리즘은 모든 정점의 쌍을 구해야 할때 사용하는 문제로 N의 크기가 비교적 작을때 사용한다.
// (N이 보통적으로 400이하일때 사용)
// 
// 벨만포드는 음의 가중치가 존재할때 사용하는 알고리즘이다.
// 
//
