#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <sstream>
#include <algorithm>
using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer;

    unordered_map<string, unordered_set<string>> reportList;
    unordered_map<string, vector<string>> idList;
    vector<string> banList;

    for (auto e : report)
    {
        stringstream ss(e);
        string userID{};
        string reportID{};
        ss >> userID >> reportID;
        reportList[reportID].insert(userID);
        idList[userID].push_back(reportID);
    }
    for (auto e : reportList)
    {
        if (e.second.size() >= k)
        {
            banList.push_back(e.first);
        }
    }
    for (auto e : id_list)
    {
        int sum{};
        for (auto k : banList)
        {
            if (find(idList[e].begin(), idList[e].end(), k) != idList[e].end())
            {
                sum++;
            }
        }
        answer.push_back(sum);
    }
    return answer;
}

int main()
{
    vector<string> id_list{ "muzi", "frodo", "apeach", "neo" };
    vector<string> report{ "muzi frodo", "apeach frodo", "frodo neo", "muzi neo", "apeach muzi" };
    int k{2};
    solution(id_list, report, k);
}