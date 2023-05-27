#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    vector<int> firP{ 1,2,3,4,5 };
    vector<int> secP{ 2,1,2,3,2,4,2,5 };
    vector<int> thrP{ 3,3,1,1,2,2,4,4,5,5 };

    vector<int> count(3, 0);
    for (int i = 0; i < answers.size(); i++)
    {
        if (answers[i] == firP[(i % firP.size())])
        {
            count[0]++;
        }
        if (answers[i] == secP[(i % secP.size())])
        {
            count[1]++;
        }
        if (answers[i] == thrP[(i % thrP.size())])
        {
            count[2]++;
        }
    }
    int maxScore = *max_element(count.begin(), count.end());
    for (int i = 0; i < count.size(); i++)
    {
        if (maxScore == count[i])
        {
            answer.push_back(i + 1);
        }
    }
    return answer;
}