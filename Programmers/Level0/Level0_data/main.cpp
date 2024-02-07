#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

map<string, int> CHECKLIST{{"code", 0}, { "date",1 }, { "maximum",2 }, { "remain",3 }};
int _sortBy;

bool comp(vector<int>& a, vector<int>& b)
{
    return a[_sortBy] < b[_sortBy];
}

vector<vector<int>> solution(vector<vector<int>> data, string ext, int val_ext, string sort_by) {
    vector<vector<int>> answer;

    int extN = CHECKLIST[ext];
    for (auto e : data)
    {
        if (e[extN] < val_ext)
        {
            answer.push_back(e);
        }
    }
    _sortBy = CHECKLIST[sort_by];
    sort(answer.begin(), answer.end(), comp);
    return answer;
}

int main()
{
    vector<vector<int>> data {{1, 20300104, 100, 80}, { 2, 20300804, 847, 37 }, { 3, 20300401, 10, 8 }};
    string ext{ "date" };
    int val_ext{ 20300501 };
    string sort_by{ "remain" };
    solution(data, ext, val_ext, sort_by);
    return 0;
}