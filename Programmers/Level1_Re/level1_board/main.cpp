#include <string>
#include <vector>

using namespace std;
const int dh[] = { 0, 1, -1, 0 };
const int dw[] = { 1, 0, 0, -1 };
int solution(vector<vector<string>> board, int h, int w) {
    int answer = 0;
    string nowColor = board[h][w];
    int maxH = board.size();
    int maxW = board[0].size();
    for (int i = 0; i < 4; i++)
    {
        int nh = h + dh[i];
        int nw = w + dw[i];
        if (nh < 0 || nh >= maxH || nw < 0 || nw >= maxW)
        {
            continue;
        }
        if (board[nh][nw] == nowColor)
        {
            answer++;
        }
    }

    return answer;
}