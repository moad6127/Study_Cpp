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
        answer++;
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
                answer--;
                break;
            }
        }
    }
    return answer;
}
int main()
{
    //vector<int> enemy{10,1,2,11,12};
    vector<int> enemy{4, 2, 4, 5, 3, 3, 1};
    solution(7, 3, enemy);
}