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

#include <bits/stdc++.h>


using namespace std;

const int V{ 10 };
vector<int> adj[V];
bool visit[V];

void Func(int start)
{
	visit[start] = true;
	cout << start << endl;

	for (int i = 0; i < adj[start].size(); i++)
	{
		if (visit[start])
		{
			continue;
		}

		Func(adj[start][i]);
	}
}

int main()
{

	adj[1].push_back(2);
	adj[1].push_back(3);

	adj[2].push_back(1);
	
	adj[3].push_back(1);
	adj[3].push_back(4);

	adj[4].push_back(3);

	for (int i = 0; i < V; i++)
	{
		if (adj[i].size() && !visit[i])
		{
			Func(i);
		}
	}
}