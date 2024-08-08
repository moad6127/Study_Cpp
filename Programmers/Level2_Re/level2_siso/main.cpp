#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

vector<pair<int, int>> CHECK({ {2,2},{2,3},{2,4},{3,4} });

bool Check(int left, int right)
{
    for (auto e : CHECK)
    {
        if (left * e.second == right * e.first)
        {
            return true;
        }
    }
    return false;
}

long long solution(vector<int> weights) {
    long long answer = 0;
    sort(weights.begin(), weights.end());

    for (int i = 0; i < weights.size(); i++)
    {
        for (int j = i + 1; j < weights.size(); j++)
        {
            if (weights[i] * 2 < weights[j])
            {
                break;
            }
            if (Check(weights[i], weights[j]))
            {
                answer++;
            }
        }
    }
    return answer;
}
int main()
{
    solution({ 100, 180, 360, 100, 270 });
}