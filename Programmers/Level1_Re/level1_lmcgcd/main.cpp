#include <string>
#include <vector>

using namespace std;
int gcd(int n, int m)
{
    int k = n % m;
    while (k != 0)
    {
        n = m;
        m = k;
        k = n % m;
    }
    return m;
}
int lcm(int n, int m)
{
    return (n * m) / gcd(n, m);
}

vector<int> solution(int n, int m) {
    vector<int> answer;
    answer.push_back(gcd(n, m));
    answer.push_back(lcm(n, m));
    return answer;
}

int main()
{
    solution(1428, 833);
}