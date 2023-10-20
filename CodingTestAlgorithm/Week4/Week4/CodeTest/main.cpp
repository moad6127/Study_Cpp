
#include <bits/stdc++.h>

using namespace std;

long three_numbers(int t, vector<int> d) {
    long result{};
    sort(d.begin(), d.end());

    for (int i = 0; i < d.size() - 2; i++)
    {
        for (int j = i + 1; j < d.size() - 1; j++)
        {
            long check = d[i] + d[j];
            long dis = t - check;

            for (int k = j + 1; k < d.size(); k++)
            {
                if (d[k] > dis)
                {
                    break;
                }
                result++;
            }
            //long lower = lower_bound(d.begin() + j + 1, d.end(), dis) - d.begin();
            //long upper = upper_bound(d.begin() + j + 1, d.end(), dis) - d.begin();

            //result += upper - lower;

        }
    }

    return result;
}

int GetMaxTime(vector<int> initialEnergy, long th) {

    int result{};
    int sum{};
    int plusEn = initialEnergy.size();
    queue<int> que;
    sort(initialEnergy.begin(), initialEnergy.end());
    for (auto e : initialEnergy)
    {
        sum += e;
        que.push(e);
    }
    while (que.size())
    {

        int now = que.front();
        int era{};
        if (now == result)
        {
            while (true)
            {
                if (now == que.front())
                {
                    que.pop();
                    era++;
                }
                else
                {
                    break;
                }
            }
        }
        plusEn -= era;
        sum -= plusEn;
        result++;
        if (sum < th)
        {
            break;
        }
    }


    return result;
}

vector<int> a;
int result;
void Func(int here, int num, bool prev)
{
    if (here == a.size())
    {
        result = max(num, result);
        return;
    }
    //지금 버린다
    if (!prev)
    {
        Func(here + 1, num, true);
    }
    //안버린다.
    Func(here + 1, num + a[here], false);
}

int GetMaxScore(vector<int> scores) {

    int resultOut{};
    a = scores;
    Func(0, 0, false);
    resultOut = result;




    return resultOut;
}
int main()
{
    vector<int> a{-1, -1, 0 ,1};
    GetMaxScore(a);
}