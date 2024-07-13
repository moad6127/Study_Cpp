#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;


bool solution(vector<string> phone_book) {
    bool answer = true;
    unordered_map<string, int> mp;
    for (auto e : phone_book)
    {
        mp[e] = 1;
    }
    for (int i = 0; i < phone_book.size(); i++)
    {
        string temp;
        for (int j = 0; j < phone_book[i].size(); j++)
        {
            temp += phone_book[i][j];
            if (mp[temp])
            {
                if (temp != phone_book[i])
                {
                    return false;
                }
            }
        }
    }

    return answer;
}
int main()
{
    solution({ "119", "97674223", "1195524421" });
}