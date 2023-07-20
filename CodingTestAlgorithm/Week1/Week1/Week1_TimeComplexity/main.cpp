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

	// O(N + M)�� �ð� ���⵵�� ������.

}

int go(int l, int r) {
	if (l == r) return a[l];
	int mid = (l + r) / 2;
	int sum = go(l, mid) + go(mid + 1, r);
	return sum;


	// n = 5�϶� 9���� ���� ������ 
	// n = 10�ϰ�� 19���� ���� ������
	//�ð����⵵�� 2n + 1�� ���⵵�� ������


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

	//log(n+1)�� ���⵵�� ������
	//big-oǥ������� O(logn)�� ������

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
//	// i = 1�϶� j = 0;
//	// i = 2�϶� j = 0,1
//	// i = 3�϶� j = 0,1,2
//	//.......
//	// �� ���� �Լ��� �ð����⵵�� 1/2(n^2 - n)�� �ȴ�
//	// BigOǥ����� O(n^2)�� �ȴ�
//	return 0 ;
//}
