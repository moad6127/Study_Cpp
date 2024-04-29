#include <string>
#include <vector>
#include <algorithm>
using namespace std;
const vector<int> m1{1, 2, 3, 4, 5};
const vector<int> m2{2, 1, 2, 3, 2, 4, 2, 5};
const vector<int> m3{3, 3, 1, 1, 2, 2, 4, 4, 5, 5};

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    int m1P{};
    int m2P{};
    int m3P{};
    for (int i = 0; i < answers.size(); i++)
    {
        if (m1[i % m1.size()] == answers[i])
        {
            m1P++;
        }
        if (m2[i % m2.size()] == answers[i])
        {
            m2P++;
        }
        if (m3[i % m3.size()] == answers[i])
        {
            m3P++;
        }
    }
    int m = max(m1P, max(m2P, m3P));
    if (m1P == m)
    {
        answer.push_back(1);
    }
    if (m2P == m)
    {
        answer.push_back(2);
    }
    if (m3P == m)
    {
        answer.push_back(3);
    }
    return answer;
}
int main()
{
    solution({ 1, 2, 3, 4, 5 });
}