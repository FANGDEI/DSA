//P4392 [BOI2007]Sound 静音问题
#include <iostream>
#include <algorithm>
using namespace std;
const int N = 1e6 + 5;
// const int N = 10;
const int INF = 0x3f3f3f3f;
struct Node {
    int l, r, minVal ,maxVal, val;
} tree[N << 2];
int a[N], n, m, c, minval, maxval;
void build(int l, int r, int p) {
    tree[p].l = l, tree[p].r = r;
    if (tree[p].l == tree[p].r) {
        tree[p].val = a[l];
        tree[p].minVal = tree[p].maxVal = a[l];
        return ;
    }
    int m = l + (r - l >> 1);
    build(l, m, p << 1);
    build(m + 1, r, p << 1 | 1);
    tree[p].minVal = min(tree[p << 1].minVal, tree[p << 1 | 1].minVal);
    tree[p].maxVal = max(tree[p << 1].maxVal, tree[p << 1 | 1].maxVal);
}
void ask(int l, int r, int p) {
    if (tree[p].l >= l && tree[p].r <= r) {
        minval = min(minval, tree[p].minVal);
        maxval = max(maxval, tree[p].maxVal);
        return ;
    }
    int m = tree[p].l + (tree[p].r - tree[p].l >> 1);
    if (l <= m) ask(l, r, p << 1);
    if (r > m) ask(l, r, p << 1 | 1);
}
int main() {
    cin >> n >> m >> c;
    for (int i=1; i<=n; i++) cin >> a[i];
    build(1, n, 1);
    bool flag = true;
    for (int i=1; i+m-1<=n; i++) {
        minval = INF, maxval = -INF;
        ask(i, i + m - 1, 1);
        if (maxval - minval <= c) {
            flag = false;
            cout << i << endl;
        }
    }
    if (flag) cout << "NONE" << endl;
    return 0;
}