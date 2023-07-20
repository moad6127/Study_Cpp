#include <bits/stdc++.h>

using namespace std;
//누적합(prefixSum)

//승철이는 뇌를 잃어버렸다.
// 학교에 갔더니 선생님이 자연수로 이루어진 N개의 카드를 주며 M개의 질문을 던진다.
// 그 질문은 나열한 카드 중 A번째부터 B번째까지의 합을 구하는 것이다.
// 뇌를 잃어버렸기 때문에 승철이는 이 문제를 풀 수 없다.문제를 풀 수 있는 프로그램을 작성해보자.
//
// 입력
//
//수의 개수 N, 합을 구해야 하는 횟수 M, 그 이후 N개의 수가 주어진다.
// 수는 100 이하의 자연수.그 이후 M개의 줄에는 합을 구해야 하는 구간 A, B가 주어진다.
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