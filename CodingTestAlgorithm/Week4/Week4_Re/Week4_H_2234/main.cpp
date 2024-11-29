

// 내가 푼 풀이 정답
//#include <bits/stdc++.h>	
//
//using namespace std;
//
//const int dx[] = { -1,0,1,0 };
//const int dy[] = { 0,-1,0,1 };
//const int nums[] = { 1,2,4,8 };
////서, 북, 동, 남
//
//int n, m;
//int a[51][51], visited[51][51];
//vector<int> result(3, 0);
//
//int dfs(int y, int x)
//{
//	visited[y][x] = 1;
//	int ret{ 1 };
//	for (int i = 0; i < 4; i++)
//	{
//		if (a[y][x] & (1 << i))
//		{
//			continue;
//		}
//		int ny = y + dy[i];
//		int nx = x + dx[i];
//		if (visited[ny][nx])
//		{
//			continue;
//		}
//		if (ny < 0 || ny >= m || nx < 0 || nx >= n)
//		{
//			continue;
//		}
//		ret += dfs(ny, nx);
//	}
//	return ret;
//}
//
//int main()
//{
//	cin >> n >> m;
//	for (int i = 0; i < m; i++)
//	{
//		for (int j = 0; j < n; j++)
//		{
//			cin >> a[i][j];
//		}
//	}
//	for (int i = 0; i < m; i++)
//	{
//		for (int j = 0; j < n; j++)
//		{
//			if (!visited[i][j])
//			{
//				result[0]++;
//				result[1] = max(dfs(i, j), result[1]);
//			}
//		}
//	}
//	for (int i = 0; i < m; i++)
//	{
//		for (int j = 0; j < n; j++)
//		{
//			for (int k = 0 ; k<4;k++)
//			{
//				if (a[i][j] & (1 << k))
//				{
//					memset(visited, 0, sizeof(visited));
//					a[i][j] -= nums[k];
//					result[2] = max(dfs(i, j), result[2]);
//					a[i][j] += nums[k];
//				}
//			}
//		}
//	}
//	for (auto e : result)
//	{
//		cout << e << '\n';
//	}
//}
// 인강 풀이

#include <bits/stdc++.h>
using namespace std;
const int dy[] = { 0, -1, 0, 1 };
const int dx[] = { -1, 0, 1, 0 };
int visited[51][51], a[51][51], cnt, compSize[2504], n, m, mx, big;
int dfs(int y, int x, int cnt) {
    if (visited[y][x]) return 0;
    visited[y][x] = cnt;
    int ret = 1;
    for (int i = 0; i < 4; i++) {
        if (!(a[y][x] & (1 << i))) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            ret += dfs(ny, nx, cnt);
        }
    }
    return ret;
}
int main() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (!visited[i][j]) {
                cnt++;
                compSize[cnt] = dfs(i, j, cnt);
                mx = max(mx, compSize[cnt]);
            }
        }
    }
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (i + 1 < m) {
                int a = visited[i + 1][j];
                int b = visited[i][j];
                if (a != b) {
                    big = max(big, compSize[a] + compSize[b]);
                }
            }
            if (j + 1 < n) {
                int a = visited[i][j + 1];
                int b = visited[i][j];
                if (a != b) {
                    big = max(big, compSize[a] + compSize[b]);
                }
            }
        }
    }
    cout << cnt << "\n" << mx << "\n" << big << '\n';
    return 0;
}