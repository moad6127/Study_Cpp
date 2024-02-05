#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<string>> board, int h, int w) {
    int answer = 0;
    int n = board.size();
    const int dh[] = { 0,1,-1,0 };
    const int dw[] = { 1,0,0,-1 };
    string checkColor = board[h][w];
    for (int i = 0; i < 4; i++)
    {
        int nh = h + dh[i];
        int nw = w + dw[i];
        if (nh >= n || nh < 0 || nw >= n || nw < 0)
        {
            continue;
        }
        if (checkColor == board[nh][nw])
        {
            answer++;
        }
    }
    
    return answer;
}