#include <string>
#include <vector>
#include <algorithm>
using namespace std;

const vector<int> DIS{40, 30, 20, 10};
vector<int> answer;

vector<int> DisCheck(vector<vector<int>> users,vector<int> disEmo, vector<int> discount)
{
    vector<int> result(2, 0);
    for (auto e : users)
    {
        int useNum{};
        for (int i = 0; i < discount.size(); i++)
        {
            if (discount[i] >= e[0])
            {
                useNum += disEmo[i];
            }
        }
        if (useNum >= e[1])
        {
            result[0]++;
        }
        else
        {
            result[1] += useNum;
        }
    }
    return result;
}

void Func(vector<vector<int>> users, vector<int> emoticons, vector<int> discount)
{
    vector<int> temp;
    if (discount.size() == emoticons.size())
    {
        vector<int> disEmo;
        for (int i = 0; i < discount.size(); i++)
        {
            int nums = emoticons[i] * ((100.f - discount[i])/100);
            disEmo.push_back(nums);
        }
        answer = max(answer, DisCheck(users, disEmo, discount));
        return;
    }
    for (int i = 0; i < DIS.size(); i++)
    {
        discount.push_back(DIS[i]);
        Func(users, emoticons, discount);
        discount.pop_back();
    }
    return;
}

vector<int> solution(vector<vector<int>> users, vector<int> emoticons) {
    answer = vector<int>(2, 0);
    Func(users, emoticons, vector<int>());
    return answer;
}

int main()
{
    vector<vector<int>> user {{40, 10000}, { 25, 10000 }};
    vector<int> emoticons{7000, 9000};
    solution(user, emoticons);

    return 0;
}