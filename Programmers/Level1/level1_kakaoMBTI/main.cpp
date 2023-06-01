#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

//RT
//CF
//JM
//AN

string solution(vector<string> survey, vector<int> choices) {
    string answer = "";
    unordered_map<char, int> list;
    for (int i = 0; i < survey.size(); i++)
    {
        int score = choices[i] - 4;
        if (score > 0)
        {
            list[survey[i][1]] += score;
        }
        else if (score < 0)
        {
            list[survey[i][0]] += (-1 * score);
        }
    }
    list['R'] >= list['T'] ? answer += 'R' : answer += 'T';
    list['C'] >= list['F'] ? answer += 'C' : answer += 'F';
    list['J'] >= list['M'] ? answer += 'J' : answer += 'M';
    list['A'] >= list['N'] ? answer += 'A' : answer += 'N';

    return answer;
}
int main()
{
    vector<string> survey{ "AN", "CF", "MJ", "RT", "NA" };
    vector<int> choices{ 5, 3, 2, 7, 5 };
    solution(survey, choices);
}