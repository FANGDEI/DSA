/*
 * @Author: FANG
 * @Date: 2021-08-05 13:03:32
 */
#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
typedef long long ll;
const int N = 1e5 + 5;
ll d[N << 2], b[N << 2];
ll a[N] = {0, 1, 2, 3, 4, 5, 6}, n;
void build(ll l, ll r, int p) {
    if (l == r) { // 为叶节点直接赋值
        d[p] = a[l];
        return ;
    }
    ll m = l + (r - l >> 1);
    build(l, m, p << 1); // 递归建立左子树
    build(m + 1, r, p << 1 | 1); // 递归建立右子树
    d[p] = d[p << 1] + d[p << 1 | 1]; // 更新
}
/* [l, r]区间范围 a 修改位置 b 修改后的值 p当前节点编号 */
void update(ll l, ll r, ll a, ll b, ll p) {
    if (l == r) {
        d[p] += b;
        return ;
    }
    ll m = l + (r - l >> 1);
    if (a <= m) update(l, m, a, b, p << 1);
    else if (a > m) update(m + 1, r, a, b, p << 1 | 1);
    d[p] = d[p << 1] + d[p << 1 | 1];
}
/* [l, r]为查询区间 [s, t]为当前节点包含的区间 p为当前节点编号 */
ll getSum(ll l, ll r, ll s, ll t, ll p) {
    if (l <= s && t <= r) return d[p]; // 当前区间为询问区间的子集时直接返回当前区间的和
    ll m = s + (t - s >> 1), sum = 0;
    if (l <= m) sum += getSum(l, r, s, m, p << 1);
    if (r > m) sum += getSum(l, r, m + 1, t, p << 1 | 1);
    return sum;
}
/* [l, r]为修改区间 [s, t]为包含当前节点的区间 c为被修改元素的变化量 p当前节点编号 */
void update(ll l, ll r, ll s, ll t, ll c, ll p) { // 区间修改
    if (l <= s && t <= r) {
        d[p] += (t - s + 1) * c;
        b[p] += c;
        return ;
    }
    ll m = s + (t - s >> 1);
    if (b[p] && s != t) { // 懒惰标记存在并且不是叶子节点
        d[p << 1] += b[p] * (m - s + 1), d[p << 1 | 1] += b[p] * (t - m);
        b[p << 1] += b[p], b[p << 1 | 1] += b[p];
        b[p] = 0;
    }
    if (l <= m) update(l, r, s, m, c, p << 1);
    if (r > m) update(l, r, m + 1, t, c, p << 1 | 1);
    d[p] = d[p << 1] + d[p << 1 | 1];
}
ll getsum(ll l, ll r, ll s, ll t, ll p) {
    if (l <= s && t <= r) return d[p];
    ll m = s + (t - s >> 1);
    if (b[p]) {
        d[p << 1] += b[p] * (m - s + 1), d[p << 1 | 1] += b[p] * (t - m);
        b[p << 1] += b[p], b[p << 1 | 1] += b[p];
        b[p] = 0;
    }
    ll sum = 0;
    if (l <= m) sum += getsum(l, r, s, m, p << 1);
    else if (r > m) sum += getsum(l, r, m + 1, t, p << 1 | 1);
    return sum;
}
int main() {
    build(1, 6, 1);
    cout << getSum(1, 3, 1, 6, 1) << endl;
    update(1, 6, 2, 1, 1);
    cout << getSum(1, 3, 1, 6, 1) << endl;
    return 0;
}