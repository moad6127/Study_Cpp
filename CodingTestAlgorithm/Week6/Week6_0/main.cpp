#include <bits/stdc++.h>
using namespace std;

//
// 
// 1. 이분탐색 
// 
// 이분탐색은 어떤 경우의 수를 하기에는 조금 애매하거나
//  n이 무지막지하게 클때 LogN의 복잡도로 탐색하기위해 시도하는 알고리즘
//
//  
//

// 백준 암기왕 문제
//
//typedef long long ll;
//int t, n, m, temp;
//unordered_map<int, int> mp;
//int check(int temp, vector<int>& v) {
//	int l = 0, r = v.size() - 1;
//	int mid;
//	while (l <= r) {
//		mid = (l + r) / 2;
//		if (v[mid] > temp)r = mid - 1;
//		else if (v[mid] == temp) return 1;
//		else l = mid + 1;
//	}
//	return 0;
//}
//int main() {
//	scanf("%d", &t);
//	while (t--) {
//		vector<int> v;
//		scanf("%d", &n); for (int i = 0; i < n; i++)scanf("%d", &temp), v.push_back(temp);
//		sort(v.begin(), v.end());
//		scanf("%d", &m); for (int i = 0; i < m; i++)scanf("%d", &temp), cout << check(temp, v) << "\n";
//	}
//	return 0;
//}
//
//
//
//보석 상자
//
//#define first f
//#define second s  
//typedef long long ll;
//ll n, m, a[300004], ret = 1e18;
//bool check(ll mid) {
//    ll num = 0;
//    for (int i = 0; i < m; i++) {
//        num += a[i] / mid;
//        if (a[i] % mid)num++;
//    }
//    return n >= num;
//}
//int main() {
//    cin >> n >> m;
//    ll lo = 1, hi = 0, mid;
//    for (int i = 0; i < m; i++) cin >> a[i], hi = max(hi, a[i]);
//    while (lo <= hi) {
//        mid = (lo + hi) / 2;
//        if (check(mid)) {
//            ret = min(ret, mid);
//            hi = mid - 1;
//        }
//        else lo = mid + 1;
//    }
//    cout << ret << "\n";
//    return 0;
//}
//
// 이분탐색은 while문의 구조만 알고있으면 풀수 있다.
// Low와 High를 선택한후 Low와 High의 Mid를 선택하면서 값을 줄여나가면 된다.
// 
// 
// LIS(최대증가부분수열)
// 
//가장긴 증가한는 부분 수열
//using namespace std;
//int n, a[1001], cnt[1001], ret;
//int main() {
//    scanf("%d", &n);
//    for (int i = 0; i < n; i++) {
//        scanf("%d", a + i);
//    }
//    for (int i = 0; i < n; i++) {
//        int maxValue = 0;
//        for (int j = 0; j < i; j++) {
//            if (a[j] < a[i] && maxValue < cnt[j]) maxValue = cnt[j];
//        }
//        cnt[i] = maxValue + 1;
//        ret = max(ret, cnt[i]);
//    }
//    printf("%d\n", ret);
//}
//
// 2중 for문으로 cnt의 배열에 a배열중 현재 큰수를 넣는 방법으로 구하게 된다
// N^2의 시간복잡도를 가지게 된다
// 
// 가장긴 증가하는 부분수열4
// 
// LIS Trace
// 
//using namespace std;
//int n, a[1001], ret = 1, cnt[1001], idx;
//int prev_list[1001];
//vector<int> real;
//void go(int idx) {
//    if (idx == -1) return;
//    real.push_back(a[idx]);
//    go(prev_list[idx]);
//    return;
//}
//int main() {
//    scanf("%d", &n);
//    for (int i = 0; i < n; i++) {
//        scanf("%d", &a[i]);
//    }
//    fill(prev_list, prev_list + 1001, -1);
//    fill(cnt, cnt + 1001, 1);
//    for (int i = 0; i < n; i++) {
//        for (int j = 0; j < i; j++) {
//            if (a[j] < a[i] && cnt[i] < cnt[j] + 1) {
//                cnt[i] = cnt[j] + 1;
//                prev_list[i] = j;
//                if (ret < cnt[i]) {
//                    ret = cnt[i];
//                    idx = i;
//                }
//            }
//        }
//    }
//    printf("%d\n", ret);
//    go(idx);
//    for (int i = real.size() - 1; i >= 0; i--) {
//        printf("%d ", real[i]);
//    }
//    return 0;
//}
//
//prev라는 이전값을 가지고있으면 문제를 풀수 있다
// 
//


