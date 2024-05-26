#include <string>
#include <vector>
#include <stack>
using namespace std;

const vector<int> CHECKLIST{1, 3, 2, 1};

int solution(vector<int> ingredient) {
    int answer = 0;
    stack<int> st;
    for (int i = 0; i < ingredient.size(); i++)
    {
        st.push(ingredient[i]);
        if (st.top() == 1 && st.size() >= 4)
        {
            vector<int> list;
            for (int i = 0; i < 4; i++)
            {
                list.push_back(st.top());
                st.pop();
            }
            if (list == CHECKLIST)
            {
                answer++;
            }
            else
            {
                for (int i = 0; i < 4; i++)
                {
                    st.push(list.back());
                    list.pop_back();
                }
            }
        }
    }
    return answer;
}
int main()
{
    solution({ 1, 3, 2, 1, 2, 1, 3, 1, 2 });
}