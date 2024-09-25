#include <string>
#include <vector>
#include <algorithm>

using namespace std;


int solution(string s) {
    int answer = 0;
    int mn = s.size();
    for (int i = 1; i <= s.size() / 2; i++) // 문자열 크기는 1개부터 s.size()/2까지
    {
        string com{ s.substr(0,i) };
        int count{};
        string temp;
        for (int j = 0; j < s.size(); j += com.size())
        {
            string sBuffer{ s.substr(j,com.size()) };
            if (com == sBuffer)
            {
                count++;
            }
            else
            {
                if (count > 1)
                {
                    temp += to_string(count) + com;
                }
                else
                {
                    temp += com;
                }
                com = sBuffer;
                count = 0;
                j -= com.size();
            }
        }
        if (count > 1)
        {
            temp += to_string(count) + com;
        }
        else
        {
            temp += com;
        }
        mn = min(mn, (int)temp.size());
    }
    return mn;
}

int main()
{
    solution({ "aabbaccc" });
}