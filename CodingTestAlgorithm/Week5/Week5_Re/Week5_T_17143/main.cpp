//#include <bits/stdc++.h>	
//
//using namespace std;
//
//int y, x, m, result;
//const int dy[] = { -1,1,0,0 };
//const int dx[] = { 0,0,1,-1 };
//
//struct ShInfo
//{
//	int y;
//	int x;
//	int s;
//	int d;
//	int z;
//	bool dead = false;
//};
//vector<ShInfo> v;
//int a[101][101], temp[101][101];
//
//void SharkMove()
//{
//	memset(temp, 0, sizeof(temp));
//	for (int i = 0 ;i <v.size();i++)
//	{
//		if (!v[i].dead)
//		{
//			int ny = v[i].y;
//			int nx = v[i].x;
//			for (int j = 0;j< v[i].s;j++)
//			{
//				ny += dy[v[i].d];
//				nx += dx[v[i].d];
//				if (ny < 0 || ny >= y || nx < 0 || nx >= x)
//				{
//					if (v[i].d == 0)
//					{
//						v[i].d = 1;
//					}
//					else if (v[i].d == 1)
//					{
//						v[i].d = 0;
//					}
//					else if (v[i].d == 2)
//					{
//						v[i].d = 3;
//					}
//					else
//					{
//						v[i].d = 2;
//					}
//					j--;
//					ny += dy[v[i].d];
//					nx += dx[v[i].d];
//					continue;
//				}
//			}
//
//			if (temp[ny][nx])
//			{
//				if (v[temp[ny][nx] - 1].z < v[i].z)
//				{
//					v[temp[ny][nx] - 1].dead = true;
//					temp[ny][nx] = i + 1;
//					v[i].y = ny;
//					v[i].x = nx;
//				}
//				else
//				{
//					v[i].dead = true;
//				}
//			}
//			else
//			{
//				temp[ny][nx] = i + 1;
//				v[i].y = ny;
//				v[i].x = nx;
//			}
//		}
//	}
//	memcpy(a, temp, sizeof(a));
//}
//int main()
//{
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL); cout.tie(NULL);
//
//	cin >> y >> x >> m;
//	for (int i = 0; i < m;i++)
//	{
//		ShInfo temp;
//		cin >> temp.y >> temp.x >> temp.s >> temp.d >> temp.z;
//		temp.y--;
//		temp.x--;
//		temp.d--;
//		v.push_back(temp);
//		a[temp.y][temp.x] = i + 1;
//	}
//	for (int man = 0;man < x;man++)
//	{
//		for (int dep = 0; dep < y;dep++)
//		{
//			if (a[dep][man])
//			{
//				if (!v[a[dep][man] - 1].dead)
//				{
//
//					v[a[dep][man] - 1].dead = true;
//					result += v[a[dep][man] - 1].z;
//					a[dep][man] = 0;
//					break;
//				}
//			}
//		}
//		SharkMove();
//	}
//
//	cout << result;
//}


#include <bits/stdc++.h>
#define max_n 100
using namespace std;
struct Shark {
	int y, x, s, dir, z, death;
}a[max_n * max_n];
const int dx[] = { 0, 0, 1, -1 };
const int dy[] = { -1, 1, 0, 0 };
int shark[max_n][max_n], R, C, M, ret, temp[max_n][max_n];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> R >> C >> M;
	for (int i = 1; i <= M; i++) {
		cin >> a[i].y >> a[i].x >> a[i].s >> a[i].dir >> a[i].z;
		a[i].y--; a[i].x--; a[i].dir--;

		if (a[i].dir <= 1) a[i].s %= (2 * (R - 1));
		else a[i].s %= (2 * (C - 1));

		shark[a[i].y][a[i].x] = i;
	}
	for (int t = 0; t < C; t++) {
		for (int y = 0; y < R; y++) {
			if (shark[y][t]) {
				a[shark[y][t]].death = 1;
				ret += a[shark[y][t]].z;
				shark[y][t] = 0;
				break;
			}
		}
		memset(temp, 0, sizeof(temp));
		for (int i = 1; i <= M; i++) {
			if (a[i].death) continue;

			int y = a[i].y;
			int x = a[i].x;
			int s = a[i].s;
			int d = a[i].dir;
			int ny, nx;

			while (1) {
				ny = y + s * dy[d];
				nx = x + s * dx[d];
				if (nx < C && ny < R && ny >= 0 && nx >= 0)break;
				if (d <= 1) {
					if (ny < 0) {
						s -= y;
						y = 0;
					}
					else {
						s -= R - 1 - y;
						y = R - 1;
					}
				}
				else {
					if (nx < 0) {
						s -= x;
						x = 0;
					}
					else {
						s -= C - 1 - x;
						x = C - 1;
					}
				}
				d ^= 1;
			}

			if (temp[ny][nx]) {
				if (a[temp[ny][nx]].z < a[i].z) {
					a[temp[ny][nx]].death = 1;
					temp[ny][nx] = i;
				}
				else a[i].death = 1;
			}
			else temp[ny][nx] = i;

			a[i].y = ny;
			a[i].x = nx;
			a[i].dir = d;
		}
		memcpy(shark, temp, sizeof(temp));
	}
	cout << ret << "\n";
	return 0;
}
