#include <string>
#include <vector>

using namespace std;

int solution(vector<int> bandage, int health, vector<vector<int>> attacks) {
    int answer = 0;

    int maxTime = attacks.back()[0];

    int continueCnt{1};
    int attackCnt{};
    int nowHealth{ health };
    for (int i = 1; i <= maxTime; i++)
    {
        if (nowHealth < 0)
        {
            break;
        }
        int attackTime{ attacks[attackCnt][0] };
        int attackDmg{ attacks[attackCnt][1] };
        bool attack{ false };
        if (attackTime == i)
        {
            nowHealth -= attackDmg;
            continueCnt = 0;
            attackCnt++;
            attack = true;
        }
        if (attack)
        {
            continue;
        }
        nowHealth += bandage[1];
        continueCnt++;
        if (nowHealth > health)
        {
            nowHealth = health;
        }
        if (continueCnt == bandage[0])
        {
            nowHealth += bandage[2];
            if (nowHealth > health)
            {
                nowHealth = health;
            }
            continueCnt = 0;
        }
    }
    answer = nowHealth;
    if (answer <= 0)
    {
        answer = -1;
    }
    return answer;
}

int main()
{
    vector<int> bandage{5, 1, 5};
    int health{ 30 };
    vector<vector<int>> attacks {{2, 10}, { 9, 15 }, { 10, 5 }, { 11, 5 }};
    solution(bandage, health, attacks);
}