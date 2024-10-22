#include <string>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

bool isUnique(vector<int>& comb, vector<vector<string>>& relation) {
    set<string> uniqueSet;
    for (auto& row : relation) {
        string key = "";
        for (int index : comb) {
            key += row[index];
        }
        if (uniqueSet.find(key) != uniqueSet.end()) {
            return false;
        }
        uniqueSet.insert(key);
    }
    return true;
}

bool isMinimal(vector<int>& comb, vector<vector<int>>& candidates) {
    for (auto& candidate : candidates) {
        if (includes(comb.begin(), comb.end(), candidate.begin(), candidate.end())) {
            return false;
        }
    }
    return true;
}

int solution(vector<vector<string>> relation) {
    int n = relation[0].size();
    vector<vector<int>> candidates;

    for (int i = 1; i < (1 << n); ++i) {
        vector<int> comb;
        for (int j = 0; j < n; ++j) {
            if (i & (1 << j)) {
                comb.push_back(j);
            }
        }
        if (isUnique(comb, relation) && isMinimal(comb, candidates)) {
            candidates.push_back(comb);
        }
    }

    return candidates.size();
}

int main()
{
    vector<vector<string>> relation{{"100", "ryan", "music", "2"},
        { "200", "apeach", "math", "2" },
        { "300", "tube", "computer", "3" },
        { "400", "con", "computer", "4" },
        { "500", "muzi", "music", "3" },
        { "600", "apeach", "music", "2" }};
    solution(relation);
}