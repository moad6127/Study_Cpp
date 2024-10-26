#include <bits/stdc++.h>

using namespace std;

string ltrim(const string&);
string rtrim(const string&);

long sumVips(vector<int> score, int guilder_count, int k) {

    long result{};
    priority_queue<pair<int, bool>> pq;
    int left{};
    int right = score.size() - 1;
    for (int i = 0; i < k; i++)
    {
        //앞에서부터 넣기
        pq.push({ score[left++],true });
        //뒤에서부터 넣기
        // 만약 2*k보다 score가 작다면 더 넣지 않는다
        if (left < right)
        {
            pq.push({ score[right--],false });
        }
    }
    for (int i = 0; i < guilder_count; i++)
    {
        pair<int, bool> maxNum = pq.top();
        pq.pop();
        result += maxNum.first;
        cout << maxNum.first<<'\n';
        if (left > right)
        {
            continue;
        }
        if (maxNum.second)
        {
            pq.push({ score[left],true });
            left++;
        }
        else
        {
            pq.push({ score[right],false });
            right--;
        }
    }

    return result;
}

int minDeletions(vector<int> arr) {
    // LIS구하기
    vector<int> LIS;
    for (auto e : arr)
    {
        auto itr = lower_bound(LIS.begin(), LIS.end(), e);
        if (itr == LIS.end())
        {
            LIS.push_back(e);
        }
        else
        {
            *itr = e;
        }
    }

    return 0;
}

const string P = "programmer";

bool check(vector<int>& arr, vector<int>& temp)
{
    for (int i = 0; i < P.size(); i++)
    {
        if (temp[P[i] - 'a'] != arr[P[i] - 'a'])
        {
            return false;
        }
    }
    return true;
}

int programmerStrings(string s) {

    vector<int> Temp(26, 0);
    for (auto e : P)
    {
        Temp[e - 'a']++;
    }
    vector<int> arrLeft(26, 0);
    vector<int> arrRight(26, 0);
    int left{};
    int right{};
    int result{};
    for (int i = 0; i < s.size(); i++)
    {
        arrLeft[s[i] - 'a']++;
        //left길이
        left++;
        if (check(arrLeft, Temp))
        {
            break;
        }
    }
    reverse(s.begin(), s.end());
    for (int i = 0; i < s.size(); i++)
    {
        arrRight[s[i] - 'a']++;
        //right길이
        right++;
        if (check(arrRight, Temp))
        {
            break;
        }
    }
    result = s.size() - (right + left);
    return result;
}

int main()
{
    //sumVips({ 8,6,18,8,14,10,12,18,9 }, 8, 3);
    //minDeletions({ 5,1,2,6,4,3 });
    programmerStrings("progxrammerrxproxgrammer");
    //findMinWeight({ 2,2,3 }, 1);
    //Moves({ 4,13,10,21,20 });
}
//
//long sumVips(vector<int> score, int guilder_count, int k) {
//
//    long result{};
//    vector<int> score_temp(score.size(), 0);
//    // guilder_count만큼 실행하기
//    for (int i = 0; i < guilder_count; i++)
//    {
//        int maxNum{};
//        int removeNum{};
//        int leftK{ k };
//        int rightK{ k };
//        for (int j = 0; j < leftK; j++)
//        {
//            if (j >= score.size())
//            {
//                break;
//            }
//            if (score_temp[j])
//            {
//                leftK++;
//                continue;;
//            }
//            if (maxNum < score[j])
//            {
//                maxNum = score[j];
//                removeNum = j;
//            }
//        }
//        for (int j = score.size() - 1; j > score.size() - rightK - 1; j--)
//        {
//            if (j < 0)
//            {
//                break;
//            }
//            if (score_temp[j])
//            {
//                rightK++;
//                continue;;
//            }
//            if (maxNum < score[j])
//            {
//                maxNum = score[j];
//                removeNum = j;
//            }
//        }
//        score_temp[removeNum] = 1;
//        //score.erase(score.begin() + removeNum);
//        result += maxNum;
//    }
//    return result;
//}

//int findMinWeight(vector<int> weights, int d) {
//    priority_queue<int, vector<int>, greater<>> pq;
//    int result{};
//    for (auto e : weights)
//    {
//        pq.push(e);
//    }
//    for (int i = 0; i < d; i++)
//    {
//        int maxNum = pq.top();
//        pq.pop();
//        maxNum = floor(maxNum / 2.f);
//        pq.push(maxNum);
//    }
//    while (pq.size())
//    {
//        result += pq.top();
//        pq.pop();
//    }
//    return result;
//}

//int Moves(vector<int> arr) {
//    vector<bool> temp;
//    int result{};
//    while (true)
//    {
//        int left{};
//        int right{};
//        for (int i = 0; i < arr.size(); i++)
//        {
//            if (arr[i] & 1)
//            {
//                left = i;
//                break;
//            }
//        }
//        for (int i = arr.size() - 1; i >= 0; i--)
//        {
//            if (arr[i] % 2 == 0)
//            {
//                right = i;
//                break;
//            }
//        }
//        if (left >= right)
//        {
//            break;
//        }
//        swap(arr[left], arr[right]);
//        result++;
//    }
//
//    return result;
//}


