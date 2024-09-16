#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(int n, int k, vector<int> enemy) {
    int answer = 0;
    priority_queue<int> pq;

    for (int i = 0; i < enemy.size(); i++)
    {
        n -= enemy[i];
        pq.push(enemy[i]);
        if (n < 0)
        {
            if (k)
            {
                n += pq.top();
                pq.pop();
                k--;
            }
            else
            {
                return i;
            }
        }
    }
    return enemy.size();
}

int main()
{
    solution(2, 4, { 3,3,3,3 });
}