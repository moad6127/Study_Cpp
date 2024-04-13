#include <string>
#include <vector>

using namespace std;
	

const vector<string> NUMS{"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
int solution(string s) {
    string temp;
    while (s.size())
    {
        if (s[0] >= '0' && s[0] <='9')
        {
            temp += s[0];
            s = s.substr(1);
            continue;
        }
        for (int i = 0; i < NUMS.size(); i++)
        {
            if (s.find(NUMS[i]) == 0)
            {
                temp += i + '0';
                s = s.substr(NUMS[i].size());
                break;
            }
        }
    }

    return stoi(temp);
}

int main()
{
    solution("one4seveneight");
}