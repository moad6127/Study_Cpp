#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;

    vector<int> st(n + 1, 1);
    for (auto e : lost)
    {
        st[e]--;
    }
    for (auto e : reserve)
    {
        st[e]++;
    }
    for (int i = 1; i <= n; i++)
    {
        if (st[i] == 2)
        {
            if (st[i - 1] == 0)
            {
                st[i]--;
                st[i - 1]++;
            }
            else if (st[i + 1] == 0)
            {
                st[i]--;
                st[i + 1]++;
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if (st[i] >= 1)
        {
            answer++;
        }
    }

    return answer;
}

int main()
{

}