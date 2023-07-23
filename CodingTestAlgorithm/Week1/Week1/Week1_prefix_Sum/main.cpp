#include <bits/stdc++.h>

using namespace std;
//������(prefixSum)

//��ö�̴� ���� �Ҿ���ȴ�.
// �б��� ������ �������� �ڿ����� �̷���� N���� ī�带 �ָ� M���� ������ ������.
// �� ������ ������ ī�� �� A��°���� B��°������ ���� ���ϴ� ���̴�.
// ���� �Ҿ���ȱ� ������ ��ö�̴� �� ������ Ǯ �� ����.������ Ǯ �� �ִ� ���α׷��� �ۼ��غ���.
//
// �Է�
//
//���� ���� N, ���� ���ؾ� �ϴ� Ƚ�� M, �� ���� N���� ���� �־�����.
// ���� 100 ������ �ڿ���.�� ���� M���� �ٿ��� ���� ���ؾ� �ϴ� ���� A, B�� �־�����.
//

int main()
{
	int M{}, N{};
	cin >> N >> M;
	vector<int> pSum(N + 1, 0);
	for (int i = 1; i <= N; i++)
	{
		int a{};
		cin >> a;
		pSum[i] = pSum[i - 1] + a;
	}
	for (int i = 0; i < M; i++)
	{
		int a{}, b{};
		cin >> a >> b;
		cout << pSum[b] - pSum[a - 1] << endl;
	}

}