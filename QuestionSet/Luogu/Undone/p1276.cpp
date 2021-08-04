//P1276 校门外的树（增强版）
#include <iostream>
#include <algorithm>
using namespace std;
const int N = 10e4 + 5;
struct A {
    bool have;
    bool tag;
    A() {
        this->have = true;
        this->tag = false;
    }
} a[N];
int n, m;
int sum1[N], sum2[N];
int lowbit(int x) {
    return x & -x;
}
void update(int i, int k) {
    int x = i;
    while (i <= n) {
        sum1[i] += k;
        sum2[i] += (x - 1) * k;
        i += lowbit(i);
    }
}
int getSum(int i) {
    int res = 0;
    int x = i;
    while (i > 0) {
        res += x * sum1[i] - sum2[i];
        i -= lowbit(i);
    }
    return res;
}
int main() {
    cin >> n >> m;
    // cout << a[1].have << a[1].tag << endl;
    a[0].have = false;
    for (int i=1; i<=n+1; i++) update(i, a[i].have - a[i].have);
    while (m--) {
        int o, x, y;
        cin >> o >> x >> y;
        if (o == 0) {
            
        }
    }
    return 0;
}