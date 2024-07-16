#include <string>
#include <vector>
#include <stack>
using namespace std;

vector<int> solution(vector<int> numbers) {
    vector<int> answer(numbers.size(),-1);
    stack<pair<int,int>> st;
    for (int i = 0; i < numbers.size(); i++)
    {
        while (st.size())
        {
            if (st.top().first >= numbers[i])
            {
                break;
            }
            answer[st.top().second] = numbers[i];
            st.pop();
        }

        st.push({ numbers[i],i });
    }
    return answer;
}

int main()
{
    solution({ 2, 3, 3, 5 });
}