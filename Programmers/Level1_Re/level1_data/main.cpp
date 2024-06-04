#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

unordered_map<string, int> DATAMAP{{"code", 0}, { "date",1 }, { "maximum" ,2 }, { "remain",3 }};
int SORT;
bool comp(vector<int>& a, vector<int>& b)
{
    return a[SORT] < b[SORT];
}

vector<vector<int>> solution(vector<vector<int>> data, string ext, int val_ext, string sort_by) {
    vector<vector<int>> answer;
    SORT = DATAMAP[sort_by];
    for (auto e : data)
    {
        if (e[DATAMAP[ext]] < val_ext)
        {
            answer.push_back(e);
        }
    }
    sort(answer.begin(), answer.end(), comp);
    return answer;
}