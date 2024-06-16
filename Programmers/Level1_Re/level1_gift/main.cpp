#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

int solution(vector<string> friends, vector<string> gifts) {
    int answer = 0;

    unordered_map<string, int> giftScore;
    unordered_map<string, unordered_map<string, int>> list;
    unordered_map<string, int>giftcnt;
    for (auto e : gifts)
    {
        string in;
        string out;
        in = e.substr(0, e.find(" "));
        out = e.substr(e.find(" ") + 1);
        giftScore[in]++;
        giftScore[out]--;
        list[in][out]++;
        list[out][in]--;
    }
    for (int i = 0; i < friends.size(); i++)
    {
        for (int j = i + 1; j < friends.size(); j++)
        {
            if (list[friends[i]][friends[j]] > list[friends[j]][friends[i]])
            {
                giftcnt[friends[i]]++;
            }
            else if (list[friends[i]][friends[j]] < list[friends[j]][friends[i]])
            {
                giftcnt[friends[j]]++;
            }
            else
            {
                if (giftScore[friends[i]] > giftScore[friends[j]])
                {
                    giftcnt[friends[i]]++;;
                }
                else if (giftScore[friends[i]] < giftScore[friends[j]])
                {
                    giftcnt[friends[j]]++;;
                }
            }
        }
    }
    for (auto e : giftcnt)
    {
        answer = max(answer, e.second);
    }

    return answer;
}
int main()
{
    vector<string> f{"muzi", "ryan", "frodo", "neo"};
    vector<string> g{"muzi frodo", "muzi frodo", "ryan muzi", "ryan muzi", "ryan muzi", "frodo muzi", "frodo ryan", "neo muzi"};
    solution(f, g);
}