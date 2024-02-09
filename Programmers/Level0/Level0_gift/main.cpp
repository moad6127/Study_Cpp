#include <string>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

int solution(vector<string> friends, vector<string> gifts) {
    int answer = 0;

    map<string, map<string, int>> check;
    map<string, int> giftCount;

    for (auto e : gifts)
    {
        stringstream ss;
        ss.str(e);
        string f, s;
        ss >> f >> s;
        giftCount[f]++;
        giftCount[s]--;
        check[f][s]++;
        check[s][f]--;
    }
    for (auto e : friends)
    {
        for (auto& k : check)
        {
            if (e == k.first)
            {
                continue;
            }
            k.second[e];
        }
    }
    for (auto e : check)
    {
        int num{};
        for (auto k : e.second)
        {
            if (k.second > 0)
            {
                num++;
            }
            if (k.second == 0)
            {
                if (giftCount[e.first] > giftCount[k.first])
                {
                    num++;
                }
            }
        }
        answer = max(answer, num);
    }
    return answer;
}
int main()
{
    vector<string> friends{"muzi", "ryan", "frodo", "neo"};
    vector<string> gifts{"muzi frodo", "muzi frodo", "ryan muzi", "ryan muzi", "ryan muzi", "frodo muzi", "frodo ryan", "neo muzi"};
    solution(friends, gifts);
}