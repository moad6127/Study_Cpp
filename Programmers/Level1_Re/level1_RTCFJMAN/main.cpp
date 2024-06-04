#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

vector<pair<char, char>> INDEX{{'R', 'T'}, {'C','F'}, {'J','M'}, {'A','N'}};

string solution(vector<string> survey, vector<int> choices) {
    string answer = "";
    unordered_map<char, int> data;
    for (int i = 0; i < choices.size(); i++)
    {
        if (choices[i] < 4)
        {
            data[survey[i][0]] += 4 - choices[i];
        }
        else if (choices[i] > 4)
        {
            data[survey[i][1]] += choices[i] - 4;
        }
    }
    for (auto e : INDEX)
    {
        if (data[e.first] >= data[e.second])
        {
            answer.push_back(e.first);
        }
        else
        {
            answer.push_back(e.second);
        }
    }
    return answer;
}

int main()
{

}