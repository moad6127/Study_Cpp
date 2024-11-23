#include <string>
#include <vector>

using namespace std;

int TimeToInt(string s)
{
    int m = stoi(s.substr(0, 2));
    int sec = stoi(s.substr(3));

    return 60 * m + sec;
}
string IntToTime(int i)
{
    string M = "00";
    string Sec = "00";
    M += to_string(i / 60);
    Sec += to_string(i % 60);
    string ret = M.substr(M.size() - 2) + ":" + Sec.substr(Sec.size() - 2);

    return ret;
}

string solution(string video_len, string pos, string op_start, string op_end, vector<string> commands) {
    string answer = "";
    int opStr = TimeToInt(op_start);
    int opEnd = TimeToInt(op_end);
    int POS = TimeToInt(pos);
    int videoLen = TimeToInt(video_len);
    if (POS >= opStr && POS <= opEnd)
    {
        POS = opEnd;
    }
    for (auto e : commands)
    {
        if (POS >= opStr && POS <= opEnd)
        {
            POS = opEnd;
        }
        if (e == "prev")
        {
            POS -= 10;
            if (POS < 0)
            {
                POS = 0;
            }
        }
        else
        {
            POS += 10;
            if (POS > videoLen)
            {
                POS = videoLen;
            }
        }
    }
    if (POS >= opStr && POS <= opEnd)
    {
        POS = opEnd;
    }
    answer = IntToTime(POS);
    return answer;
}

int main()
{
    solution("10:00", "00:03", "00:00", "00:05", { "prev","next"});
}