
#include <bits/stdc++.h>

using namespace std;

vector<int> solution(vector<int> arr, vector<vector<int>> queries) {
    vector<int> answer;
    for (auto e : queries)
    {
        int check{ e[2] };
        int m{1000004};
        for (int i = e[0]; i <= e[1]; i++)
        {
            if (arr[i] > check)
            {
                m = min(m, arr[i]);
            }

        }
        if (m == 1000004)
        {
            answer.push_back(-1);
        }
        else
        {
            answer.push_back(m);
        }
    }
    return answer;
}