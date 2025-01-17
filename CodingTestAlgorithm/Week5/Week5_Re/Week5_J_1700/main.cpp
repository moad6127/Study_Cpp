//#include <bits/stdc++.h>
//
//using namespace std;
//
//int n, k, result;
//int a[101], visited[104];
//vector<int> v;
//int main()
//{
//	cin >> n >> k;
//	for (int i = 0; i < k;i++)
//	{
//		cin >> a[i];
//	}
//	for (int i = 0;i < k;i++)
//	{
//		if (!visited[a[i]])
//		{
//			if (v.size() == n)
//			{
//				int last_idx{};
//				int pos{};
//				for (auto e : v)
//				{
//					int here_Pick = INT32_MAX;
//					for (int j = i + 1;j < k;j++)
//					{
//						if (e == a[j])
//						{
//							here_Pick = j;
//							break;
//						}
//					}
//					if (last_idx < here_Pick)
//					{
//						last_idx = here_Pick;
//						pos = e;
//					}
//				}
//				visited[pos] = 0;
//				result++;
//				v.erase(find(v.begin(), v.end(), pos));
//			}
//			v.push_back(a[i]);
//			visited[a[i]] = 1;
//		}
//	}
//	cout << result;
//}
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N, K;
    cin >> N >> K;
    vector<int> order(K);
    for (int i = 0; i < K; i++) {
        cin >> order[i];
    }

    vector<int> multitap;
    int unplugCount = 0;

    for (int i = 0; i < K; i++) {
        if (find(multitap.begin(), multitap.end(), order[i]) != multitap.end()) {
            continue;
        }

        if (multitap.size() < N) {
            multitap.push_back(order[i]);
        }
        else {
            int farthest = -1, index = -1;
            for (int j = 0; j < N; j++) {
                int nextUse = find(order.begin() + i + 1, order.end(), multitap[j]) - order.begin();
                if (nextUse == order.end() - order.begin()) {
                    index = j;
                    break;
                }
                else if (nextUse > farthest) {
                    farthest = nextUse;
                    index = j;
                }
            }
            multitap[index] = order[i];
            unplugCount++;
        }
    }

    cout << unplugCount << endl;
    return 0;
}
