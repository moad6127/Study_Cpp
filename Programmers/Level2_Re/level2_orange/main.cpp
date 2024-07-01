#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;



int solution(int k, vector<int> tangerine) {
    int answer = 0;
    unordered_map<int, int> mp;
    for (int i = 0; i < tangerine.size(); i++)
    {
        mp[tangerine[i]]++;
    }
    vector<pair<int, int>> sortV;
    for (auto e : mp)
    {
        sortV.push_back({ e.second,e.first });
    }
    sort(sortV.begin(), sortV.end(),greater<>());
    int i{};
    while (true)
    {
        if (k <= 0)
        {
            break;
        }
        k -= sortV[i++].first;
        answer++;
    }
    return answer;
}

int main()
{
    solution(6, { 1, 3, 2, 5, 4, 5, 2, 3 });
}