
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

long long fact(int n) {
    if (n == 1) return 1;
    else return n * fact(n - 1);
}
vector<int> solution(int n, long long k) {
    vector<int> answer;
    vector<int> v;
    for (int i = 1; i <= n; i++) v.push_back(i);
    while (n > 0) {
        long long f = fact(n) / n;
        int index = (k - 1) / f;
        if (index < 0) index = 0;
        answer.push_back(v[index]);
        v.erase(v.begin() + index);
        n--;
        k %= f;
        if (k == 0) k = f;
    }
    return answer;
}