#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer;

    unordered_map<string, unordered_set<string>> reportList;
    unordered_map<string, int> id;

    for (auto e : report)
    {
        string id;
        string re;
        id = e.substr(0,e.find(" "));
        re = e.substr(e.find(" ") + 1);
        reportList[re].insert(id);
    }
    for (auto e : reportList)
    {
        if (e.second.size() >= k)
        {
            for (auto k : e.second)
            {
                id[k] += 1;
            }
        }
    }
    for (auto e : id_list)
    {
        answer.push_back(id[e]);
    }

    return answer;
}

int main()
{
    vector<string>id_list{"muzi", "frodo", "apeach", "neo"};
    vector<string> report{"muzi frodo", "apeach frodo", "frodo neo", "muzi neo", "apeach muzi"};
    solution(id_list, report,2);
}