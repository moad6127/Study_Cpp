#include <string>
#include <vector>
#include <unordered_set>
#include <bits/stdc++.h>


using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer{0,0};
    unordered_set<string> list;
    char prevWord{words[0].back()};
    list.insert(words[0]);

    for (int i = 1; i < words.size(); i++)
    {
        auto itr = list.insert(words[i]);
        if (itr.second)
        {
            if (words[i].front() == prevWord)
            {
                prevWord = words[i].back();
            }
            else
            {
                answer[0] = (i % n) + 1;
                answer[1] = (i / n) + 1;
                break;
            }
        }
        else
        {
            answer[0] = (i % n) + 1;
            answer[1] = (i / n) + 1;
            break;
        }

    }

    return answer;
}