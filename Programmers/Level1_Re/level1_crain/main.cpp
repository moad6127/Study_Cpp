#include <string>
#include <vector>
#include <stack>
using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    stack<int> st;
    for (int i = 0; i < moves.size(); i++)
    {
        int x{ moves[i] - 1 };
        int y{};
        while (true)
        {
            if (y >= board.size())
            {
                break;
            }
            if (board[y][x])
            {
                if (!st.empty())
                {
                    if (st.top() == board[y][x])
                    {
                        st.pop();
                        answer += 2;
                    }
                    else
                    {
                        st.push(board[y][x]);
                    }
                }
                else
                {
                    st.push(board[y][x]);
                }
                board[y][x] = 0;
                break;
            }
            y++;
        }
    }
    return answer;
}