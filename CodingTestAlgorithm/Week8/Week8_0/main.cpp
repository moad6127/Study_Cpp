//
//
// 
// 
// 8���� �˰��� ���� ����Ʈ��, �ִܰŸ�
// 
// 
// ����Ʈ��
// 
// ����Ʈ�� ����� �ڷᱸ���̸� ���׸�Ʈ Ʈ���� ������ ������ �ִ�.
// 
// ���׸�Ʈ Ʈ����?
// 
// ����Ʈ���߿� � ������ ���� ����ȭ�� ���� ��Ƶδ°��� ���Ѵ�.
// 
// ����Ʈ���� �̷��� Ư¡�� ����ִ�/
// 
// ���� Ʈ���� ������ ��带 �����ϸ� ������Ʈ �ϴ� Ʈ���� ���Ѵ�.
// ���׸�Ʈ�� �ٸ��� ��� ���׸�Ʈ�� ���� �ʿ䰡 ���� ȿ�������� ����ϴ� Ʈ���̴�.
// 
// ���� 2042 ������ ����
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
//[��ó] [�˰��� ����] 8����.����Ʈ���� �ִܰŸ��˰���(���ͽ�Ʈ��, �÷��̵����, ��������) | �ۼ��� ū��
//
// 
// �̶� ������ ����
// �Է��� ������ 1�� �ε������� �ޱ� �����Ѵ�.
// 
// 
// ���� 3653 ��ȭ���� ����
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
//[��ó] [�˰��� ����] 8����.����Ʈ���� �ִܰŸ��˰���(���ͽ�Ʈ��, �÷��̵����, ��������) | �ۼ��� ū��
//
// 
// 
// 
// 
// �ִܰŸ� �˰���
// 
// BFS���� ����� �˰����� ����ġ�� ������� ����Ҽ� ������, ����ġ�� �ٸ����
// �̷��� �ִܰŸ� �˰����� ����ؼ� Ǯ���Ѵ�.
// 
// ���ͽ�Ʈ�� �˰���
// 
// ���� ����ġ�� ���� �׷������� ����Ҽ� �ִ�.
// 
// �켱����ť�� PQ�� �ִ� �������� �ش����������� �Ÿ��� ���峷�� ������ �߽����� �Ÿ��迭�� �����ϸ�
// �ٽ� ť�� �ִ� ������ �ݺ��Ͽ� ���������� �Ÿ��迭�� �ϼ��ϴ� �˰����̴�.
// 
// ���� v���� �Ÿ��� ���ؼ� ��ª�� ��쿡 ������ �Ѵ�.
// dist[u] + w[u,v] = dist[v]�� �����Ѵ�.
// 
// 
// 
// ���� 1753 �ִܰ�ι���
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
//[��ó] [�˰��� ����] 8����.����Ʈ���� �ִܰŸ��˰���(���ͽ�Ʈ��, �÷��̵����, ��������) | �ۼ��� ū��
//
// dist�� �ִ�ġ�� ���صд�.
// 
// 
// 
// �÷��̵����� �˰���
// 
// ��� �� �ִܰŸ� �˰����Դϴ�. 
// u���� v�� ���µ� �������� ��ġ�°� �� �����ٸ� ��ȭ�� ���� �Ÿ��迭�� ���Ž��� ������ ���Դϴ�.
// �� �÷��̵� ������ ��� �� �ִܰŸ���θ� ���ϱ⵵ �ϰ�
//  i, j�� ������, ������������ ����Ǿ��ִ����� Ȯ���� �� �ֽ��ϴ�.
//  ���� �׷����� ������ ���� ���� �ֽ��ϴ�. ������ �ð����⵵�� �������?
//  V�� 3�����Դϴ�. ���� �� �˰����� �������� N �� ũ�Ⱑ ������� ���� �� �� �� �ֽ��ϴ�.
//
// 
// ����	11404 ����
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
//[��ó] [�˰��� ����] 8����.����Ʈ���� �ִܰŸ��˰���(���ͽ�Ʈ��, �÷��̵����, ��������) | �ۼ��� ū��
//
//
// ���������� dist[i][j]�� ����� �˰������� 
// k,i,j�� ������ ��� �صΰ� 2���� �迭�� �����ϸ鼭 i���� j���� ���� �ִܰŸ��� ���ϴ� �˰����̴�.
// 
// 
// 
// ���� ��Ʈ �˰���
// 
// ���� ����ġ�� �ִ� �׷����� ��� ����ϴ� �ִܰŸ� �˰���
// ���ͽ�Ʈ��� �޸� ���� ����ġ�� �����Ұ�� ����ϴ� �˰����̴�.
// 
// Ÿ�Ӹӽ�, ��Ȧ ���� �������·� ���ư��� ����ϴ� �˰����̴�.
// 
// 
// ���� 11657 Ÿ�Ӹӽ� ����
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
//[��ó] [�˰��� ����] 8����.����Ʈ���� �ִܰŸ��˰���(���ͽ�Ʈ��, �÷��̵����, ��������) | �ۼ��� ū��
//
//
// �̷��� 3������ �ִܰŸ��˰����� �����ϸ� ���Ȳ�϶� ����ϸ� ������ �˾ƾ� �Ѵ�.
// 
// ���ͽ�Ʈ�� �˰����� ���������� ������ �����Ҷ� ����ϸ� N�� ũ�Ⱑ ũ��
// ���� ����ġ�� �������� ������� ����Ѵ�.
// 
// �÷��̵� �˰����� ��� ������ ���� ���ؾ� �Ҷ� ����ϴ� ������ N�� ũ�Ⱑ ���� ������ ����Ѵ�.
// (N�� ���������� 400�����϶� ���)
// 
// ��������� ���� ����ġ�� �����Ҷ� ����ϴ� �˰����̴�.
// 
//
