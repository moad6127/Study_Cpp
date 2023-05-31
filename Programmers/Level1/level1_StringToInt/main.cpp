#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

//0	zero
//1	one
//2	two
//3	three
//4	four
//5	five
//6	six
//7	seven
//8	eight
//9	nine

int solution(string s) {

    unordered_map<string, char> list{ {"zero",'0'},{"one",'1'},{"two",'2'},{"three",'3'},{"four",'4'},{"five",'5'},{"six",'6'},{"seven",'7'},{"eight",'8'},{"nine",'9'}};
    string temp{};
    while (true)
    {
        if (s.empty())
        {
            break;
        }

        if (s.front() >= '0' && s.front() <= '9')
        {
            temp += s.front();
            s = s.substr(1);
        }
        else
        {
            for (auto e : list)
            {
                if (s.find(e.first) == 0)
                {
                    temp += e.second;
                    s = s.substr(e.first.length());
                    break;
                }
            }
        }
    }

    return stoi(temp);
}

int main()
{
    string s{ "one4seveneight" };
    solution(s);
}