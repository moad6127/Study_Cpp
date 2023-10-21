
#include <bits/stdc++.h>

using namespace std;

long long countCombinations(vector<int>& nums, int T) {
    int N = nums.size();
    sort(nums.begin(), nums.end()); // ����

    long long count = 0;

    for (int i = 0; i < N; i++) {
        int target = T - nums[i];
        int left = i + 1, right = N - 1;

        while (left < right) {
            int sum = nums[left] + nums[right];
            if (sum <= target) {
                count += (right - left); // B�� ������ ����� ������ A�� C�� ���� ��
                left++;
            }
            else {
                right--;
            }
        }
    }

    return count;
}
long long countCombinations_Sec(vector<int>& nums, int T) {
    int N = nums.size();
    sort(nums.begin(), nums.end()); // ����

    long long count = 0;

    for (int a = 0; a < N; a++) {
        for (int b = a + 1; b < N; b++) {
            int target = T - nums[a] - nums[b];

            // ���� �˻��� ���� C�� ������ ã��
            int left = b + 1, right = N - 1;
            int pos = upper_bound(nums.begin() + left, nums.begin() + right + 1, target) - nums.begin();

            if (pos > b)
                count += pos - b - 1; // ������ C�� ����
        }
    }

    return count;
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
    //���� ������
    if (!prev)
    {
        Func(here + 1, num, true);
    }
    //�ȹ�����.
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
    vector<int> a{-1, -1, 0 ,1,-92,102,2030,1040,-231};
    //GetMaxScore(a);

    vector<int> check{1, 2, 3, 4, 5};
    countCombinations_Sec(check, 8);

}