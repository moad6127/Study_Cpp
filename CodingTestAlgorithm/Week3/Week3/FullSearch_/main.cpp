//
//
// ����Ž���� ���󺹱�
// 
// ����Ž���Ҷ� ���󺹱��� �ʿ��� ����
// ������ ���°��� ������ ���°��� ������ �ټ� �ֱ� ������
// 
// 
// �⺻���� ����Ž���� ���󺹱�
// 
//#include <bits/stdc++.h>
//using namespace std;
//int visited[4];
//vector<int> adj[4];
//vector<int> v;
//void print() {
//	for (int i : v) cout << char(i + 'A') << " ";
//	cout << '\n';
//}
//
//void go(int idx) {
//	if (v.size() == 3) {
//		print(); return;
//	}
//	for (int there : adj[idx]) {
//		if (visited[there]) continue;
//		visited[there] = 1;
//		v.push_back(there);
//		go(there);
//		visited[there] = 0;
//		v.pop_back();
//	}
//}
//int main() {
//	adj[0].push_back(1);
//	adj[1].push_back(2);
//	adj[1].push_back(3);
//	adj[1].push_back(0);
//	adj[2].push_back(1);
//	adj[3].push_back(1);
//
//	visited[0] = 1;
//	v.push_back(0);
//	go(0);
//	return 0;
//}
//[��ó] [�˰��� ����] 3����.����Ž��, ��Ʈ��ŷ | �ۼ��� ū��
//
// ���� EX)
//
#include <bits/stdc++.h>
using namespace std;

int a[3][3] = {
{ 10, 20, 21 },
{ 70, 90, 12 },
{ 80, 110, 120 } };
int visited[3][3];
vector<int> coins;
const int dy[4] = { -1, 1, 0 ,0 };
const int dx[4] = { 0,0,-1, 1 };

void Func(int y, int x)
{
	if (y == 2 && x == 2)
	{
		for (auto e : coins)
		{
			cout << e << " ";
		}
		cout << '\n';
		return;
	}

	for (int i = 0; i < 4; i++)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny < 0 || ny >= 3 || nx < 0 || nx >= 3)
		{
			continue;
		}
		if (!visited[ny][nx])
		{
			visited[ny][nx] = 1;
			coins.push_back(a[ny][nx]);
			Func(ny, nx);
			coins.pop_back();
			visited[ny][nx] = 0;
		}
	}
}

int main()
{
	visited[0][0] = 1;
	coins.push_back(a[0][0]);
	Func(0, 0);

}