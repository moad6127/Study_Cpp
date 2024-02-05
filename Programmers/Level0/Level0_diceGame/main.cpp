#include <string>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

int solution(int a, int b, int c, int d) {
    int answer = 10;
    map<int, int> m;
    m[a]++;
    m[b]++;
    m[c]++;
    m[d]++;
    if (m.size() == 4)
    {
        for (auto e : m)
        {
            answer = min(answer, e.first);
        }
    }
    else if (m.size() == 3)
    {
        int q{}, r{};
        for (auto e : m)
        {
            if (e.second == 1)
            {
                if (q == 0)
                {
                    q = e.first;
                }
                else
                {
                    r = e.first;
                }

            }
        }
        answer = q * r;
    }
    else if (m.size() == 2)
    {
        if (m.begin()->second == 2)
        {
            vector<pair<int, int>> v(m.begin(), m.end());
            answer = (v[0].first + v[1].first) * (abs(v[0].first - v[1].first));
        }
        else
        {
            int p{}, q{};
            for (auto e : m)
            {
                if (e.second == 3)
                {
                    p = e.first;
                }
                if (e.second == 1)
                {
                    q = e.first;
                }
            }
            answer = (10 * p + q) * (10 * p + q);
        }
    }
    else
    {
        answer = 1111 * a;
    }

    return answer;
}
int main()
{
    solution(2, 5, 2, 6);
}