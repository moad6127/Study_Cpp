#include <string>
#include <vector>
#include <stack>
using namespace std;

int solution(vector<int> order) {
    int needOrder{ 0 };
    stack<int> second;
    for (int in = 1; in <= order.size(); in++)
    {
        second.push(in);
        while (second.top() == order[needOrder])
        {
            second.pop();
            needOrder++;
            if (second.empty())
            {
                break;
            }
        }
    }
    return needOrder;
}
int main()
{
    solution({5,4,3,2,1});
}