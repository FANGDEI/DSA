// 单点更新 区间查询 前缀和数组
// 区间更新 单点查询 差分数组维护
#include <iostream>
#include <algorithm>
using namespace std;
const int N = 1e5 + 5;
int n;
int a[N], sum[N];
int lowbit(int x) {
    return x & (-x);
}
void build() {
    for (int i=1; i<=n; i++) {
        for (int j=i; j>i-lowbit(i); j--) {
            sum[i] += a[j];
        }
    }
}
void update(int i, int k) {
    while (i <= n) {
        sum[i] += k;
        i += lowbit(i); // sum[x]节点的父节点为 sum[x + lowbit(x)]
    }
}
int ask(int i) { // a[1] + ... + a[i] 的和
    int res = 0;
    while (i > 0) {
        res += sum[i];
        i -= lowbit(i);
    }
    return res;
}
// void update(int i, int k) { // 区间修改 区间求值
//     int x = i;
//     while (i <= n) {
//         sum1[i] += k;
//         sum2[i] += k * (x - 1);
//         i += lowbit(i);
//     }
// }
// int getsum(int i) {        //求前缀和
//      int res = 0, x = i;
//      while(i > 0){
//          res += x * sum1[i] - sum2[i];
//          i -= lowbit(i);
//      }
//      return res;
// }
// void add(int l, int r, int v) {
//     update(l, v), update(r + 1, -v);
// }
// int getSumXY(int l, int r) {
//     return getsum(r) - getsum(l - 1);
// }
int main() {
    cin >> n;
    for (int i=1; i<=n; i++) cin >> a[i], update(i, a[i]);
    int ans = ask(4);
    cout << ans << endl;
    return 0;
}