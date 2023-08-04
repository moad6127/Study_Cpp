//Graph
//
// 
// ����, ����, �ܹ��� ����, ����� ����
// 
// 
// 
// Tree
// 
// ����� �̷���� ������, �θ���� �ڽĳ��� �̷���� ���������� �Ǿ��ִ�.
// 
// ������ �׷����� �̷�����ִ�. ����Ŭ�� ����.
// 
// Vertex - 1 = Edge ��� ���� �ִ�.(���� - 1 = ����)
// 
// ���δٸ� �� ��� ������ ��δ� ���Ϲ����ϸ� �ݵ�� �����Ѵ�.
//
// 
// ��Ʈ���� ���� �����ִ� ����̴�
// ���� or�������� Ʈ���� �־����� ��Ʈ ������ Ȯ���ϴ°��� ����.
// 
// 
// ���� ���� �ڽ��� ���� ����̴�.
// 
// ���γ��� ������ ���� ���̿� �ִ� ��带 ���Ѵ�.
// 
// Ʈ������ ���̴� ��帶�� �ٸ��� ��Ʈ���� Ư�� ������ �ִܰŸ��� ������ �Ÿ��� ���Ѵ�
// ���̴� ��Ʈ���� �������� ���� ��Ÿ��� ���Ѵ�.
// 
// 
// ���� Ʈ��
// 
//	�� ����� �ڽ��� ���� 2�� �����ϰ�� ���� Ʈ����� �Ѵ�.
// 
// 
// ���� Ž�� Ʈ��
// 
// ���� Ʈ���� �������� ������ ����Ʈ������ ����� ������ ū���� �ִ� ��常 �ְ� ���� ����Ʈ���� ��庸��
// ���� ������ �ִ� ������ ����ִ� Ʈ��.
// 
// 
// �׷��� �����ϱ�
//  ���� ���
//  
// ������ �׷����� ����� �׷����� ����
// 
// ��������� ������ ������ ���踦 ��Ÿ���� boolŸ���� ���簢 ����̴�.
// 
// 
// ex)
//   0  1  2  3
// 0    1  1  1
// 1 1     1
// 2 1  1
// 3 1
// 
// a[from][to] �� ǥ���ϸ� ����Ǿ�������1(true)�� ǥ���Ѵ�
// ����Ǿ����� ������ 0(false)�� ǥ���Ѵ�
// 
//Q. 3����忡�� 5������ ���� �ܹ��� ��ΰ� �ְ� �̸� ������ķ� ǥ���Ѵٸ� ��� �ɱ��? 
//[��ó][�˰��� ����] 2����.�׷����̷�, �������, ��������Ʈ, DFS, BFS, Ʈ����ȸ | �ۼ��� ū��
// 
// a[3][5] = 1
// 
// ����

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
// ���� ����Ʈ
// 
// ���������� ����� ����Ʈ�� �����.
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
//    // �̷��Ե� �� �� �ִ�.
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
//[��ó][�˰��� ����] 2����.�׷����̷�, �������, ��������Ʈ, DFS, BFS, Ʈ����ȸ | �ۼ��� ū��
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
// ���� ��İ� ��������Ʈ�� ����
// 
// ���� ���⵵
// ���� ��� = O(V^2)
// ���� ����Ʈ = O(V + E)
// 
// �ð� ���⵵
// 
// ���� �Ѱ� ã��
// 
// ������� = O(1)
// ���� ����Ʈ = O(V)
// 
// ���� ����� �ٷ� ã���� �ִ�.
// 
//
// ��� ������ ã������ �ð����⵵
// 
// �������= O(V^2)
// ���� ����Ʈ = O(V+E)
// 
// ���� �׷����� ����Ҷ��� ��������Ʈ, �����Ҷ��� ���� ����� ����
// 
// 
// 
// ������ ���� ����Ʈ�� ��������� �׽�Ʈ���� ��ķ� �־������ �״�� Ǫ�°� ����.
// 
// 
// 
// Map���� ��Ÿ�� ������ 
// 
// 
// 1�� 0���� �̷���� ������ �Ǿ������� 1�� �����ְ� 0�� �������°��϶� ����ϴ� �����
// 
// ����������� �̷������������ ������ ������� Ǯ��� �Ѵ�.
// 
// 
// Q1.  {0, 0}��ǥ���� dy, dx�� ����� 4����(��, ������, �Ʒ�, ����)�� Ž���ϸ� ��ǥ�� ����Ͻÿ�.
//[��ó][�˰��� ����] 2����.�׷����̷�, �������, ��������Ʈ, DFS, BFS, Ʈ����ȸ | �ۼ��� ū��
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
// Q. 3 * 3 ���� �Է¹޾ƾ� ��. �� ���� 1�� 0���� �̷�����ְ� {0, 0}�� ������ 1���� �����Ѵ�. {0, 0}���� 4������ �������� ��ĭ�� Ž���س����� �湮�� ������ �ٽ� �湮���� ������ �湮�ϴ� ��ǥ�� ����ϴ� �ڵ�. 0�� �� �� ���� ����. 1�� �� �� �ִ� ������ �����Ͻÿ�.
//[��ó][�˰��� ����] 2����.�׷����̷�, �������, ��������Ʈ, DFS, BFS, Ʈ����ȸ | �ۼ��� ū��
// 
// ���� 
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
// ����� ������Ʈ
// 
// ����� ���� �׷����� �ִ� �׷����� �ְ� ���� �ϳ��� ����� �ִ°Ͱ� ����.
// ������ �����׷����� �����׷����� �������� ����Ǿ� �ִ�.
// 
// �̷��� ����� ������Ʈ ���� �����ִ°��� Ǯ������(floodfill)�̶�� �Ѵ�.
// 
// 
// 
// 
// 
// DFS(���� �켱 Ž��)
// 
// �׷����� Ž���Ҷ� ����ϴ� �˰������� ���� �����ִ� ������ Ž������ ���ƿͼ� Ž���Ѵ�.
// �湮�� ���� �ٽ� �湮���� �ʴ´�.
// ��������� �湮�Ѵ�.
// 
// �����ڵ�
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
    cout << u << "�κ��� ���۵� �Լ��� ����Ǿ����ϴ�.\n";
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
4�κ��� ���۵� �Լ��� ����Ǿ����ϴ�.
5
5�κ��� ���۵� �Լ��� ����Ǿ����ϴ�.
2�κ��� ���۵� �Լ��� ����Ǿ����ϴ�.
3
3�κ��� ���۵� �Լ��� ����Ǿ����ϴ�.
1�κ��� ���۵� �Լ��� ����Ǿ����ϴ�.
*/
//[��ó][�˰��� ����] 2����.�׷����̷�, �������, ��������Ʈ, DFS, BFS, Ʈ����ȸ | �ۼ��� ū��


//
// 
//���� Ǯ��
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
// BFS �ʺ� �켱 Ž��
// 
// �������� �����ؼ� ���� ������ �������� �������� ���� ������ ��� Ž���ϸ鼭 �����ϴ� �˰����̴�
// 
// BFS�� Queue�� ����ؼ� �˰����� �����
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
    cout << "10�����κ��� 24������ �ִܰŸ��� : " << visited[24] - 1 << '\n';
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
10�����κ��� 24������ �ִܰŸ��� : 3

[��ó][�˰��� ����] 2����.�׷����̷�, �������, ��������Ʈ, DFS, BFS, Ʈ����ȸ | �ۼ��� ū��

*/

//
//
//����

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
//  DFS �� BFS ���̾˾ƺ���
// 
// DFS�� BFS�� ��� �׷����� Ž���Ҷ� ���ȴ�.
// 
// DFS �� �޸𸮸� ������ϰ� �������� ���Ҽ� �ִ�, �ڵ尡 �� ª�� ����Ž������� ����Ҷ� ����Ѵ�
// BFS �� �޸𸮸� ������ϰ� ����ġ�� ���� �׷������� �ִܰŸ� �˰����� ����Ҽ� �ִ�. �ڵ尡 �� ���.
// 
// 
// 
// 
// Ʈ�� ��ȸ
// 
// 
// 
// ��ȸ ��ȸ
// ������ȸ(postorder traversal)�� �ڽ� ��带 ���� �湮�ϰ� �ڽ��� ��带 �湮�ϴ� ���� ���Ѵ�
// 
// ���� �ڵ�
// postorder( node )
//  if (node.visited == false)
//  postorder(node->left)
//  postorder(node->right)
//  node.visited = true
//[��ó][�˰��� ����] 2����.�׷����̷�, �������, ��������Ʈ, DFS, BFS, Ʈ����ȸ | �ۼ��� ū��
// 
// 
// ���� ��ȸ
// 
// ������ȸ(preorder traversal) �� �ڽ��� ��带 ���� �湮�ϰ� �ڽ��� ��带 �湮�ϴ°��� ���Ѵ�(DFS ����� �����ϸ� �ȴ�.)
// 
// ���� �ڵ�
// preorder( node )
//  if (node.visited == false)
//  node.visited = true
//  preorder(node->left)
//  preorder(node->right)
//[��ó][�˰��� ����] 2����.�׷����̷�, �������, ��������Ʈ, DFS, BFS, Ʈ����ȸ | �ۼ��� ū��
// 
// 
// ���� ��ȸ
// 
// ������ȸ(inorder traversal) �� ���� ��带 ���� �湮�ϰ� �ڽ��� ��带 �湮�Ѵ��� ������ ��带 �湮�ϴ°��� ���Ѵ�.
// 
// ���� �ڵ�
// inorder( node )
//  if (node.visited == false)
//  inorder(node->left)
//  node.visited = true
//  inorder(node->right)
//[��ó][�˰��� ����] 2����.�׷����̷�, �������, ��������Ʈ, DFS, BFS, Ʈ����ȸ | �ۼ��� ū��
// 
// 
// 
//