#include <string>
#include <vector>
#include <iostream>
#include <unordered_set>

using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer;
    unordered_set<string> checkList;
    char prevWord{words[0].back()};
    int endGame{};
    checkList.insert(words[0]);
    for (int i = 1; i < words.size(); i++)
    {
        if (!checkList.insert(words[i]).second || prevWord != words[i].front())
        {
            endGame = i;
            break;
        }
        prevWord = words[i].back();
    }
    if (endGame == 0)
    {
        return { 0,0 };
    }
    return {(endGame % n) + 1, (endGame / n) + 1};
}

int main()
{
    solution(3, { "tank", "kick", "know", "wheel", "land", "dream", "mother", "robot", "tank" });
}