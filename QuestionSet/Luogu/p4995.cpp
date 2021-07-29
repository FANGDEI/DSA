//跳跳
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll; // 不开longlong见祖宗了
vector<int> v;
int n;
int a[305];
int main() {
    cin >> n;
    for (int i=1; i<=n; i++) cin >> a[i], v.push_back(a[i]);
    sort(v.begin(), v.end());
    ll ans = (v.back() - 0) * (v.back() - 0);
    bool flag = true;
    while (1) {
        if (flag) {
            ans += (v.back() - v.front()) * (v.back() - v.front());
            v.pop_back();
            flag = false;
            if (v.empty()) break;
        } else if (!flag) {
            ans += (v.front()-v.back()) * (v.front()-v.back());
            v.erase(v.begin());
            flag = true;
            if (v.empty()) break;
        }
    }
    cout << ans << endl;
    return 0;
}