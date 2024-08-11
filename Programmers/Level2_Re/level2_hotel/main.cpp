#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int time(string a)
{
    int h = stoi(a.substr(0, 2));
    int m = stoi(a.substr(3));
    return h * 60 + m;
}

int solution(vector<vector<string>> book_time) {
    int answer = 0;
    sort(book_time.begin(), book_time.end());
    vector<int> room;
    for (int i = 0; i < book_time.size(); i++)
    {
        if (!room.size())
        {
            room.push_back(time(book_time[i][1]) + 10);
        }
        else
        {
            bool flag{false};
            for (auto& e : room)
            {
                if (e <= time(book_time[i][0]))
                {
                    e = time(book_time[i][1]) + 10;
                    flag = true;
                    break;
                }
            }
            if (!flag)
            {
                room.push_back(time(book_time[i][1]) + 10);
            }
        }
    }

    return room.size();
}
int main()
{
    solution({ {"09:10", "10:10"},
        {"10:20", "12:20"}});

}