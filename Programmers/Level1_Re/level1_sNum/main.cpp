#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> arr)
{
    vector<int> answer;
    stack<int> st;
    for (auto e : arr)
    {
        if (st.empty())
        {
            st.push(e);
        }
        else
        {
            if (st.top() == e)
            {
                continue;
            }
            else
            {
                st.push(e);
            }
        }
    }
    int n = st.size();
    for (int i = 0; i < n; i++)
    {
        answer.push_back(st.top());
        st.pop();
    }
    reverse(answer.begin(), answer.end());

    return answer;
}

int main()
{
    solution({ 1,1,3,3,0,1,1 });
}