#include <string>
#include <vector>
#include <map>
using namespace std;

vector<int> solution(vector<string> name, vector<int> yearning, vector<vector<string>> photo) {
    vector<int> answer;
    map<string, int> m;
    for (int i = 0; i < name.size(); i++)
    {
        m[name[i]] = yearning[i];
    }
    for (int i = 0; i < photo.size(); i++)
    {
        int score{};
        for (auto e : photo[i])
        {
            score += m[e];
        }
        answer.push_back(score);
    }
    return answer;
}