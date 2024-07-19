#include <string>
#include <vector>
#include <stack>
using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer(prices.size(),0);
    stack<int> st;
    for (int i = 0; i < prices.size(); i++)
    {
        while (st.size())
        {
            if (prices[st.top()] <= prices[i])
            {
                break;
            }
            answer[st.top()] = i - st.top();
            st.pop();
        }
        st.push(i);
    }
    int size = prices.size() - 1;
    while (st.size())
    {
        answer[st.top()] = size - st.top();
        st.pop();
    }

    return answer;
}
int main()
{
    solution({ 1, 2, 3, 2, 3 });
}