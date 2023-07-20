#include <bits/stdc++.h>

using namespace std;
int n, cnt, a[1004];

void solve(int N, int M) {
	int a = 1;
	for (int i = 0; i < N; i++) {
		a *= i;
	}
	for (int j = 0; j < M; j++) {
		a *= j;
	}
	cout << a << "\n";

	// O(N + M)의 시간 복잡도를 가진다.

}

int go(int l, int r) {
	if (l == r) return a[l];
	int mid = (l + r) / 2;
	int sum = go(l, mid) + go(mid + 1, r);
	return sum;


	// n = 5일때 9번의 식을 가지고 
	// n = 10일경우 19번의 식을 가진다
	//시간복잡도는 2n + 1의 복잡도를 가진다


}
void solve(int N) {
	int a = 0, i = N;
	while (i > 0) {
		a += i;
		i /= 2;
		cnt++;
	}
	cout << a << '\n';
	cout << cnt << endl;
}



int main() {
	cin >> n;
	solve(n);
}


//int main()
//{
//	cin >> n;
//	int a = 0;
//	for (int i = 0; i < n; i++)
//	{
//		for (int j = 0; j < i; j++)
//		{
//			a += i + j;
//			cnt++;
//		}
//	}
//
//	cout << a << endl;
//	cout << "cnt : " << cnt << endl;
//
//	// i = 1일때 j = 0;
//	// i = 2일때 j = 0,1
//	// i = 3일때 j = 0,1,2
//	//.......
//	// 즉 위의 함수의 시간복잡도는 1/2(n^2 - n)이 된다
//	// BigO표기법은 O(n^2)이 된다
//	return 0 ;
//}
