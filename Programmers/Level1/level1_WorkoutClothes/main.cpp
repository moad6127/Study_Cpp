#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    vector<int> p(n + 1, 0);
    for (auto e : lost)
    {
        p[e]--;
    }
    for (auto e : reserve)
    {
        p[e]++;
    }

    for (int i = 1; i <= n; i++)
    {
        if (p[i] == -1)
        {
            if (p[i - 1] == 1)
            {
                p[i - 1] = 0;
                p[i] = 0;
            }
            else if (p[i + 1] == 1)
            {
                p[i + 1] = 0;
                p[i] = 0;
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if (p[i] != -1)
        {
            answer++;
        }
    }
    return answer;
}