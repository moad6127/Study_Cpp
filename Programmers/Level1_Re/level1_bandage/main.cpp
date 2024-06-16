#include <string>
#include <vector>
#include <cmath>
using namespace std;

int solution(vector<int> bandage, int health, vector<vector<int>> attacks) {
    int answer = 0;

    const int MAXHealth = health;
    int cnt{};
    int now{};
    for (int i = 1; i <= 1000; i++)
    {
        if (now >= attacks.size())
        {
            break;
        }
        if (attacks[now][0] == i)
        {
            health -= attacks[now][1];
            if (health <= 0)
            {
                return -1;
            }
            now++;
            cnt = 1;
        }
        else
        {
            if (cnt == bandage[0])
            {
                health = min(MAXHealth, health + bandage[1] + bandage[2]);
                cnt = 1;
            }
            else
            {
                health = min(MAXHealth, health + bandage[1]);
                cnt++;
            }
        }
    }
    return health;
}

int main()
{
    solution({ 1,1,1 }, 5, { {1,2},{3,2} });
}