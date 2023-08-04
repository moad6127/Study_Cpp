//Graph
//
// 
// 정점, 간선, 단방향 간선, 양방향 간선
// 
// 
// 
// Tree
// 
// 노드들로 이루어져 있으며, 부모노드와 자식노드로 이루어진 계층구조로 되어있다.
// 
// 무방향 그래프로 이루어져있다. 사이클이 없다.
// 
// Vertex - 1 = Edge 라는 식이 있다.(정점 - 1 = 간선)
// 
// 서로다른 두 노드 사이의 경로는 유일무이하며 반드시 존재한다.
//
// 
// 루트노드는 가장 위에있는 노드이다
// 문제 or면접에서 트리가 주어지면 루트 노드부터 확인하는것이 좋다.
// 
// 
// 리프 노드는 자식이 없는 노드이다.
// 
// 내부노드는 리프와 리프 사이에 있는 노드를 말한다.
// 
// 트리에서 깊이는 노드마다 다르며 루트에서 특정 노드까지 최단거리로 갔을때 거리를 말한다
// 높이는 루트에서 리프까지 가장 긴거리를 말한다.
// 
// 
// 이진 트리
// 
//	각 노드의 자식의 수가 2개 이하일경우 이진 트리라고 한다.
// 
// 
// 이진 탐색 트리
// 
// 이진 트리의 일종으로 오른쪽 하위트리에는 노드의 값보다 큰값만 있는 노드만 있고 왼쪽 하위트리는 노드보다
// 작은 값들이 있는 노드들이 들어있는 트리.
// 
// 
// 그래프 구현하기
//  인접 행렬
//  
// 무방향 그래프는 양방향 그래프와 같다
// 
// 인접행렬은 정점과 간선의 관계를 나타내는 bool타입의 정사각 행렬이다.
// 
// 
// ex)
//   0  1  2  3
// 0    1  1  1
// 1 1     1
// 2 1  1
// 3 1
// 
// a[from][to] 로 표현하며 연결되어있으면1(true)로 표시한다
// 연결되어있지 않으면 0(false)로 표시한다
// 
//Q. 3번노드에서 5번노드로 가는 단방향 경로가 있고 이를 인접행렬로 표현한다면 어떻게 될까요? 
//[출처][알고리즘 강의] 2주차.그래프이론, 인접행렬, 인접리스트, DFS, BFS, 트리순회 | 작성자 큰돌
// 
// a[3][5] = 1
// 
// 문제

//
//
//#include <bits/stdc++.h>
//
//using namespace std;
//bool a[10][10];
//bool visit[10];
//
//void Visit(int start)
//{
//
//	visit[start] = 1;
//	cout << start << endl;
//	for (int i = 0; i < 10; i++)
//	{
//		if (visit[i])
//		{
//			continue;
//		}
//		if (a[start][i])
//		{
//			Visit(i);
//		}
//	}
//}
//int main()
//{
//	a[1][2] = 1;
//	a[2][1] = 1;
//	a[1][3] = 1;
//	a[3][1] = 1;
//	a[3][4] = 1;
//	a[4][3] = 1;
//
//	for (int i = 0; i < 10; i++)
//	{
//		for (int j = 0; j < 10; j++)
//		{
//			if (a[i][j] && !visit[i])
//			{
//				Visit(i);
//			}
//		}
//	}
//
//}


//
//
// 인접 리스트
// 
// 각정점마다 연결된 리스트를 만든다.
// 
// ex)
// 
// #include<bits/stdc++.h>
//using namespace std;
//const int V = 4;
//vector<int> adj[V];
//int main() {
//    adj[0].push_back(1);
//    adj[0].push_back(2);
//    adj[0].push_back(3);
//
//    adj[1].push_back(0);
//    adj[1].push_back(2);
//
//    adj[2].push_back(0);
//    adj[2].push_back(1);
//
//    adj[3].push_back(0);
//
//    for (int i = 0; i < 4; i++) {
//        cout << i << " :: ";
//        for (int there : adj[i]) {
//            cout << there << " ";
//        }
//        cout << '\n';
//    }
//    // 이렇게도 할 수 있다.
//    for (int i = 0; i < 4; i++) {
//        cout << i << " :: ";
//        for (int j = 0; j < adj[i].size(); j++) {
//            cout << adj[i][j] << " ";
//        }
//        cout << '\n';
//    }
//
//}
/*
0 :: 1 2 3
1 :: 0 2
2 :: 0 1
3 :: 0
*/
//[출처][알고리즘 강의] 2주차.그래프이론, 인접행렬, 인접리스트, DFS, BFS, 트리순회 | 작성자 큰돌
// 
//
//
// 
// 
//

//#include <bits/stdc++.h>
//
//
//using namespace std;
//
//const int V{ 10 };
//vector<int> adj[V];
//bool visit[V];
//
//void Func(int start)
//{
//	visit[start] = true;
//	cout << start << endl;
//
//	for (int i = 0; i < adj[start].size(); i++)
//	{
//		if (visit[start])
//		{
//			continue;
//		}
//
//		Func(adj[start][i]);
//	}
//}
//
//int main()
//{
//
//	adj[1].push_back(2);
//	adj[1].push_back(3);
//
//	adj[2].push_back(1);
//	
//	adj[3].push_back(1);
//	adj[3].push_back(4);
//
//	adj[4].push_back(3);
//
//	for (int i = 0; i < V; i++)
//	{
//		if (adj[i].size() && !visit[i])
//		{
//			Func(i);
//		}
//	}
//}
//
// 
// 인접 행렬과 인접리스트의 차이
// 
// 공간 복잡도
// 인접 행렬 = O(V^2)
// 인접 리스트 = O(V + E)
// 
// 시간 복잡도
// 
// 간선 한개 찾기
// 
// 인접행렬 = O(1)
// 인접 리스트 = O(V)
// 
// 인접 행렬은 바로 찾을수 있다.
// 
//
// 모든 간선을 찾을때의 시간복잡도
// 
// 인접행렬= O(V^2)
// 인접 리스트 = O(V+E)
// 
// 따라서 그래프가 희소할때는 인접리스트, 조밀할때는 인접 행렬이 좋다
// 
// 
// 
// 보통은 인접 리스트를 사용하지만 테스트에서 행렬로 주어질경우 그대로 푸는게 좋다.
// 
// 
// 
// Map으로 나타난 문제들 
// 
// 
// 1과 0으로 이루어진 맵으로 되어있을때 1은 갈수있고 0은 갈수없는곳일때 사용하는 방법들
// 
// 지도기반으로 이루어져있을때는 지도를 기반으로 풀어야 한다.
// 
// 
// Q1.  {0, 0}좌표에서 dy, dx를 만들어 4방향(위, 오른쪽, 아래, 왼쪽)을 탐색하며 좌표를 출력하시오.
//[출처][알고리즘 강의] 2주차.그래프이론, 인접행렬, 인접리스트, DFS, BFS, 트리순회 | 작성자 큰돌
// 
// 
//
//
//#include <bits/stdc++.h>
//using namespace std;
//
//int main()
//{
//	int x{}, y{};
//	int dy[] = { -1,0,1,0 };
//	int dx[] = { 0,1,0,-1 };
//
//	for (int i = 0; i < 4; i++)
//	{
//		int ny = y + dy[i];
//		int nx = x + dx[i];
//		cout << ny << " : " << nx << '\n';
//	}
//}
//
// Q. 3 * 3 맵을 입력받아야 함. 이 맵은 1과 0으로 이루어져있고 {0, 0}은 무조건 1임을 보장한다. {0, 0}부터 4방향을 기준으로 한칸씩 탐색해나가며 방문한 정점은 다시 방문하지 않으며 방문하는 좌표를 출력하는 코드. 0은 갈 수 없는 지역. 1은 갈 수 있는 지역을 구현하시오.
//[출처][알고리즘 강의] 2주차.그래프이론, 인접행렬, 인접리스트, DFS, BFS, 트리순회 | 작성자 큰돌
// 
// 맵은 
//	1 0 1
//	1 0 1
//	0 1 1
// 
//
//#include <bits/stdc++.h>
//using namespace std;
//const int dy[] = { -1,0,1,0 };
//const int dx[] = { 0,1,0,-1 };
//
//bool visit[3][3];
//bool testMap[3][3];
//
//void Func(int x, int y)
//{
//	visit[x][y] = true;
//	cout << x << " : " << y << '\n';
//	for (int i = 0; i < 4; i++)
//	{
//		int ny = y + dy[i];
//		int nx = x + dx[i];
//		if (ny < 0 || ny >= 3 || nx < 0 || nx >= 3)
//		{
//			continue;
//		}
//
//		if (testMap[ny][nx] && !visit[ny][nx])
//		{
//			Func(ny,nx);
//		}
//	}
//}
//
//int main()
//{
//	testMap[0][0] = 1;
//	testMap[0][1] = 0;
//	testMap[0][2] = 1;
//	testMap[1][0] = 1;
//	testMap[1][1] = 0;
//	testMap[1][2] = 1;
//	testMap[2][0] = 0;
//	testMap[2][1] = 1;
//	testMap[2][2] = 1;
//
//	Func(0, 0);
//}
//
// 
// 연결된 컴포넌트
// 
// 연결된 하위 그래프가 있는 그래프가 있고 각각 하나의 덩어리가 있는것과 같다.
// 각각의 하위그래프는 하위그래프의 정점들은 연결되어 있다.
// 
// 이러한 연결된 컴포넌트 끼리 묶여있는것을 풀르드필(floodfill)이라고 한다.
// 
// 
// 
// 
// 
// DFS(깊이 우선 탐색)
// 
// 그래프를 탐색할때 사용하는 알고리즘으로 가장 깊이있는 노드까지 탐색한후 돌아와서 탐색한다.
// 방문한 노드는 다시 방문하지 않는다.
// 재귀적으로 방문한다.
// 
// 수도코드
// 
// DFS(u,adj)
// 
// u->visit = true
// for v->adj[u]
// 
// if(v->visit == false)
// DFS(v,adj)

/*
#include<bits/stdc++.h>
using namespace std;

const int n = 6;
vector<int> adj[n];
int visited[n];

void dfs(int u) {
    visited[u] = 1;
    cout << u << "\n";
    for (int v : adj[u]) {
        if (visited[v] == 0) {
            dfs(v);
        }
    }
    cout << u << "로부터 시작된 함수가 종료되었습니다.\n";
    return;
}
int main() {
    adj[1].push_back(2);
    adj[1].push_back(3);
    adj[2].push_back(4);
    adj[4].push_back(2);
    adj[2].push_back(5);
    dfs(1);
}

1
2
4
4로부터 시작된 함수가 종료되었습니다.
5
5로부터 시작된 함수가 종료되었습니다.
2로부터 시작된 함수가 종료되었습니다.
3
3로부터 시작된 함수가 종료되었습니다.
1로부터 시작된 함수가 종료되었습니다.
*/
//[출처][알고리즘 강의] 2주차.그래프이론, 인접행렬, 인접리스트, DFS, BFS, 트리순회 | 작성자 큰돌


//
// 
//문제 풀이
// 
//

/*
#include <bits/stdc++.h>


using namespace std;

int N, M;
const int dy[] = { -1,0,1,0 };
const int dx[] = { 0,1,0,-1 };
bool visited[100][100];

void dfs(vector<vector<int>>& a,int y,int x)
{
    visited[y][x] = true;
    for (int i = 0; i < 4; i++)
    {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if (ny <0 || ny >=N || nx <0 || nx>=M)
        {
            continue;
        }
        if (!visited[ny][nx] && a[ny][nx])
        {
            dfs(a, ny, nx);
        }
    }
}

int main()
{
    cin >> N >> M;
    vector<vector<int>> a(N, vector<int>(M, 0));

    int result{};
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> a[i][j];
        }
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (!visited[i][j] && a[i][j])
            {
                dfs(a, i, j);
                result++;
            }
        }
    }
    cout << result;

    return 0;
}
*/
//
//
// BFS 너비 우선 탐색
// 
// 정점에서 시작해서 다음 깊이의 정점으로 가기전에 현재 레벨을 모두 탐색하면서 진행하는 알고리즘이다
// 
// BFS는 Queue를 사용해서 알고리즘을 만든다
// 
// 
//

/*
#include<bits/stdc++.h>
using namespace std;
vector<int> adj[100];
int visited[100];
int nodeList[] = { 10, 12, 14, 16, 18, 20, 22, 24 };
void bfs(int here) {
    queue<int> q;
    visited[here] = 1;
    q.push(here);
    while (q.size()) {
        int here = q.front(); q.pop();
        for (int there : adj[here]) {
            if (visited[there]) continue;
            visited[there] = visited[here] + 1;
            q.push(there);
        }
    }
}
int main() {
    adj[10].push_back(12);
    adj[10].push_back(14);
    adj[10].push_back(16);

    adj[12].push_back(18);
    adj[12].push_back(20);


    adj[20].push_back(22);
    adj[20].push_back(24);
    bfs(10);
    for (int i : nodeList) {
        cout << i << " : " << visited[i] << '\n';
    }
    cout << "10번으로부터 24번까지 최단거리는 : " << visited[24] - 1 << '\n';
    return 0;
}

10 : 1
12 : 2
14 : 2
16 : 2
18 : 3
20 : 3
22 : 4
24 : 4
10번으로부터 24번까지 최단거리는 : 3

[출처][알고리즘 강의] 2주차.그래프이론, 인접행렬, 인접리스트, DFS, BFS, 트리순회 | 작성자 큰돌

*/

//
//
//문제

/*
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N{}, M{};
    int startY{}, startX{}, endY{}, endX{};
    const int dy[] = { -1,0,1,0 };
    const int dx[] = { 0,1,0,-1 };

    cin >> N >> M >> startY >> startX >> endY >> endX;

    vector<vector<int>> a(N, vector<int>(M, 0));
    vector<vector<int>> visited(N, vector<int>(M, 0));
    visited[startY][startX] = 1;
    queue<pair<int, int>> q;
    q.push({ startY,startX });
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> a[i][j];
        }
    }
     
    while (q.size())
    {
        pair<int, int> nowPosition = q.front();
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int ny = nowPosition.first + dy[i];
            int nx = nowPosition.second + dx[i];

            if (ny < 0 || ny >= N || nx < 0 || nx >= M)
            {
                continue;
            }
            if (!visited[ny][nx] && a[ny][nx])
            {
                visited[ny][nx] = visited[nowPosition.first][nowPosition.second] + 1;
                q.push({ ny,nx });
            }
        }
    }
    cout << visited[endY][endX];
}
*/

//
//
//  DFS 와 BFS 차이알아보기
// 
// DFS와 BFS둘 모드 그래프를 탐색할때 사용된다.
// 
// DFS 는 메모리를 덜사용하고 절단점을 구할수 있다, 코드가 더 짧고 완전탐색기능을 사용할때 사용한다
// BFS 는 메모리를 더사용하고 가중치가 같은 그래프에서 최단거리 알고리즘을 사용할수 있다. 코드가 더 길다.
// 
// 
// 
// 
// 트리 순회
// 
// 
// 
// 후회 순회
// 후위순회(postorder traversal)는 자식 노드를 먼저 방문하고 자신의 노드를 방문하는 것을 말한다
// 
// 수도 코드
// postorder( node )
//  if (node.visited == false)
//  postorder(node->left)
//  postorder(node->right)
//  node.visited = true
//[출처][알고리즘 강의] 2주차.그래프이론, 인접행렬, 인접리스트, DFS, BFS, 트리순회 | 작성자 큰돌
// 
// 
// 전위 순회
// 
// 전위순회(preorder traversal) 는 자신의 노드를 먼저 방문하고 자식의 노드를 방문하는것을 말한다(DFS 방식을 생각하면 된다.)
// 
// 수도 코드
// preorder( node )
//  if (node.visited == false)
//  node.visited = true
//  preorder(node->left)
//  preorder(node->right)
//[출처][알고리즘 강의] 2주차.그래프이론, 인접행렬, 인접리스트, DFS, BFS, 트리순회 | 작성자 큰돌
// 
// 
// 중위 순회
// 
// 중위순회(inorder traversal) 는 왼쪽 노드를 먼저 방문하고 자신의 노드를 방문한다음 오른쪽 노드를 방문하는것을 말한다.
// 
// 수도 코드
// inorder( node )
//  if (node.visited == false)
//  inorder(node->left)
//  node.visited = true
//  inorder(node->right)
//[출처][알고리즘 강의] 2주차.그래프이론, 인접행렬, 인접리스트, DFS, BFS, 트리순회 | 작성자 큰돌
// 
// 
// 
//