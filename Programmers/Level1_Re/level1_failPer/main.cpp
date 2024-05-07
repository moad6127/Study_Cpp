#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool Comp(pair<float, int>& a, pair<float, int>& b)
{
    if (a.first == b.first)
    {
        return a < b;
    }
    return a.first > b.first;
}

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    int UserCount = stages.size();
    vector<int> Count(N + 2, 0);
    for (auto e : stages)
    {
        Count[e]++;
    }
    vector<pair<float, int>> v;
    for (int i = 1; i <= N; i++)
    {
        float fail = (float)Count[i] / UserCount;
        if (UserCount == 0)
        {
            fail = 0.f;
        }
        UserCount -= Count[i];
        v.push_back({ fail,i });
    }
    sort(v.begin(), v.end(), Comp);
    for (auto e : v)
    {
        answer.push_back(e.second);
    }
    return answer;
}
int main()
{
    solution(4, { 1,1,1,1,1 });
}