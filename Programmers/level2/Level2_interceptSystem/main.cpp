#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool Comp(vector<int>& a, vector<int>& b)
{
    return a[1] < b[1];
}

int solution(vector<vector<int>> targets) {
    int answer = 0;
    int end{};
    sort(targets.begin(), targets.end(),Comp);

    for (auto e : targets)
    {
        if (end <= e[0])
        {
            end = e[1];
            answer++;
        }
    }

    return answer;
}
int main()
{
    vector<vector<int>> targets {{4, 5}, { 4, 8 }, { 10, 14 }, { 11, 13 }, { 5, 12 }, { 3, 7 }, { 1, 4 }};
    solution(targets);
}