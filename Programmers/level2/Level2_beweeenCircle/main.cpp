#include <string>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

long long solution(int r1, int r2) {
    long long answer = 0;
    answer += 8;
    for (long long i = r1; i < r2; i++)
    {
        answer += long long(4*(i * 2 - 1));
    }

    return answer;
}

long long solution2(int r1, int r2) {
	long long answer = 0;

	for (int i = 1; i <= r2; i++) {
		int minY = ceil(sqrt((long long)r1 * r1 - (long long)i * i));
		int maxY = floor(sqrt((long long)r2 * r2 - (long long)i * i));

		if (r1 < i)
			minY = 0;

		answer += (maxY - minY + 1);
	}

	return answer * 4;
}
int main()
{
	cout << solution(3,4)<<'\n';
   cout << solution2(3, 4);
}