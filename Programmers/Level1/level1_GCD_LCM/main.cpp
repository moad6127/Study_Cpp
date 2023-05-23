#include <string>
#include <vector>

using namespace std;

int GCD(int a, int b)
{
    int c{};
    while (b != 0)
    {
        c = a % b;
        a = b;
        b = c;
    }
    return a;
}

int LCD(int a, int b)
{
    return a * b / GCD(a, b);
}

vector<int> solution(int n, int m) {
    vector<int> answer{GCD(n,m) , LCD(n,m)};
    return answer;
}