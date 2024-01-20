#include <bits/stdc++.h>

using namespace std;

vector<int> solution(vector<int> arr) {
    int size = arr.size();
    int needSize{ 1 };
    while (true)
    {
        if (needSize >= size)
        {
            needSize -= size;
            break;
        }
        needSize *= 2;
    }
    for (int i = 0; i < needSize; i++)
    {
        arr.push_back(0);
    }
    return arr;
}