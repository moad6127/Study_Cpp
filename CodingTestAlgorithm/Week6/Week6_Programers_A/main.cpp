#include <string>
#include <vector>
#include <algorithm>

using namespace std;
vector<int> startIdx(vector<int> weak, int start, int n)
{
    if (start == 0)
    {
        return weak;
    }
    vector<int> result;
    for (int i = start; i < weak.size(); i++)
    {
        result.push_back(weak[i]);
    }
    for (int i = 0; i < start; i++)
    {
        result.push_back(weak[i] + n);
    }
    return result;
}

int solution(int n, vector<int> weak, vector<int> dist) {
    int answer = 20;
    sort(dist.begin(), dist.end());
    do
    {
        for (int start = 0; start < weak.size(); start++)
        {
            vector<int> plusWeak = startIdx(weak, start, n);
            int idx{};
            int flag{};
            int curr = plusWeak[0] + dist[0];
            for (int i = 1; i < plusWeak.size(); i++)
            {
                if (plusWeak[i] > curr)
                {
                    if (idx + 1 == dist.size())
                    {
                        flag = 1;
                        break;
                    }
                    curr = plusWeak[i] + dist[++idx];
                }
            }
            if (!flag)
            {
                answer = min(answer, idx + 1);
            }
        }
    } while (next_permutation(dist.begin(), dist.end()));
    if (answer == 20)
    {
        return -1;
    }
    return answer;
}

int main()
{
    vector<int> weak{1, 5, 6, 10};
    vector<int> dist{1, 2, 3, 4};
    solution(12, weak, dist);
}