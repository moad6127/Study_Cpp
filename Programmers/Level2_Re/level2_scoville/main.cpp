#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    priority_queue<int,vector<int>,greater<int>> pq;
    for (auto e : scoville)
    {
        pq.push(e);
    }
    while (true)
    {
        if (pq.top() >= K)
        {
            break;
        }
        if (pq.size() < 2)
        {
            answer = -1;
            break;
        }
        int fir = pq.top();
        pq.pop();
        int sec = pq.top();
        pq.pop();
        int temp = fir + (sec * 2);
        pq.push(temp);
        answer++;
    }

    return answer;
}
int main()
{
    solution({ 1, 2, 3, 9, 10, 12 }, 7);
}