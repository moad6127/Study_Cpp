#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool Comp(pair<int, double>& a, pair<int, double>& b)
{
    if (a.second == b.second)
    {
        return a.first < b.first;
    }
    return a.second > b.second;
}

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    int size{ static_cast<int>(stages.size()) };
    vector<int> checkList(N+2,0);
    for (int i = 0; i < size; i++)
    {
        checkList[stages[i]]++;
    }
    vector<pair<int, double>> temp;
    for (int i = 1; i <= N; i++)
    {
        double fail;
        if (checkList[i] != 0)
        {
            fail = double(checkList[i]) / size;
        }
        else
        {
            fail = 0;
        }
        temp.push_back({ i,fail });
        size -= checkList[i];
    }
    sort(temp.begin(), temp.end(),Comp);
    for (auto e : temp)
    {
        answer.push_back(e.first);
    }
    return answer;
}
int main()
{
    int N{ 5 };
    vector<int> stages{ 6, 6, 6, 6, 6, 6, 6, 6 };
    solution(N, stages);
}