#include <string>
#include <vector>
#include <stack>
using namespace std;


int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;

    stack<int> st;
    for (auto e : moves)
    {
        e -= 1;
        int temp{};
        while (true)
        {
            if (temp >= board.size())
            {
                break;
            }
            if (board[temp][e] != 0)
            {
                break;
            }
            temp++;
        }
        if (temp >= board.size())
        {
            continue;
        }
        if (st.empty())
        {
            st.push(board[temp][e]);
        }
        else
        {
            if (st.top() == board[temp][e])
            {
                st.pop();
                answer += 2;
            }
            else
            {
                st.push(board[temp][e]);
            }
        }
        board[temp][e] = 0;
    }
    return answer;
}
int main()
{
    vector<vector<int>> board{ {0, 0, 0, 0, 0},{0, 0, 1, 0, 3},{0, 2, 5, 0, 1},{4, 2, 4, 4, 2},{3, 5, 1, 3, 1} };
    vector<int> moves{ 1, 5, 3, 5, 1, 2, 1, 4 };

    solution(board, moves);
}