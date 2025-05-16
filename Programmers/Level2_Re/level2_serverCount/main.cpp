#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(vector<int> players, int m, int k) {
    int answer = 0;
    queue<int> Ser;
    for (int time = 0; time < players.size();time++)
    {
        while (Ser.size())
        {
            if (Ser.front() > time)
            {
                break;
            }
            Ser.pop();
        }
        int needServer = players[time] / m;
        int Size = Ser.size();
        if (needServer > Size)
        {
            for (int i = 0; i < needServer - Size; i++)
            {
                Ser.push(time + k);
                answer++;
            }
        }

    }
    return answer;
}

int main()
{
    vector<int> players{ 0, 2, 3, 3, 1, 2, 0, 0, 0, 0, 4, 2, 0, 6, 0, 4, 2, 13, 3, 5, 10, 0, 1, 5 };
    solution(players, 3, 5);
}