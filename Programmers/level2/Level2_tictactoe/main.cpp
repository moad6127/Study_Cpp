#include <string>
#include <vector>

using namespace std;

vector<vector<int>> CHECK
    {{0,1,2}, { 3,4,5 }, { 6,7,8 },
    { 0,3,6 }, { 1,4,7 }, { 2,5,8 },
    { 0,4,8 }, { 2,4,6 }};

int CheckTic(char checChar, vector<char>& lineBoard)
{
    for (auto e : CHECK)
    {
        int cnt{};
        for (auto k : e)
        {
            if (lineBoard[k] == checChar)
            {
                cnt++;
            }
        }
        if (cnt == 3)
        {
            return 1;
        }
    }
    return 0;
}

int solution(vector<string> board) {
    int oNum{};
    int xNum{};
    vector<char> lineBoard;
    for (int i = 0; i < board.size(); i++)
    {
        for (int j = 0; j < board[0].size(); j++)
        {
            if (board[i][j] == 'O')
            {
                oNum++;
            }
            else if (board[i][j] == 'X')
            {
                xNum++;
            }
            lineBoard.push_back(board[i][j]);
        }
    }
    if (!(oNum - xNum == 0 || oNum - xNum == 1))
    {
        return 0;
    }
    if (CheckTic('O', lineBoard))
    {
        if (oNum - xNum != 1)
        {
            return 0;
        }
    }
    if (CheckTic('X', lineBoard))
    {
        if (oNum != xNum)
        {
            return 0;
        }
    }
    if (CheckTic('O', lineBoard) && CheckTic('X', lineBoard))
    {
        return 0;
    }


    return 1;
}

int main()
{
    vector<string> board{ "O.X", ".O.", "..X" };
    int check = solution(board);

    return 0;
}