#include <string>
#include <vector>
#include <unordered_map>
#include <stack>
using namespace std;

vector<int> solution(string msg) {
    vector<int> answer;
    unordered_map<string, int> dic;
    for (char init = 'A'; init <= 'Z'; init++)
    {
        string temp;
        temp.push_back(init);
        dic[temp] = init - 'A' + 1;
    }
    int count{ 27 };
    while (msg.size())
    {
        string temp = msg;
        int tempSize = temp.size();
        stack<char> st;
        for (int i = 0; i < tempSize; i++)
        {
            if (dic.count(temp) != 0)
            {
                answer.push_back(dic[temp]);
                msg = msg.substr(temp.size());
                if (!st.empty())
                {
                    temp.push_back(st.top());
                    dic[temp] = count++;
                }
                break;
            }
            else
            {
                st.push(temp.back());
                temp.pop_back();
            }
        }
    }

    return answer;
}

int main()
{
    solution("KAKAO");
}