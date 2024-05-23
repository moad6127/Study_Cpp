#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<string> keymap, vector<string> targets) {
    vector<int> answer;
    vector<int> alMaps(26,999);
    for (int i = 0; i < keymap.size(); i++)
    {
        for (int j = 0; j < keymap[i].size(); j++)
        {
            alMaps[keymap[i][j] - 'A'] = min(alMaps[keymap[i][j] - 'A'], j + 1);
        }
    }
    for (int i = 0; i < targets.size(); i++)
    {
        int result{};
        for (auto e : targets[i])
        {
            if (alMaps[e - 'A'] == 999)
            {
                result = -1;
                break;
            }
            else
            {
                result += alMaps[e- 'A'];
            }
        }
        answer.push_back(result);
    }
    return answer;
}

int main()
{
    solution({ "ABACD", "BCEFD" }, { "ABCD","AABB" });
}