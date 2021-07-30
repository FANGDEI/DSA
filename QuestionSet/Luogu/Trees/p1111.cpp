//修复公路
#include <iostream>
#include <algorithm>
using namespace std;
int n, m;
const int N = 100005;
int fa[N];
struct Node {
    int x, y, t;
    bool operator<(const Node x) {
        return this->t < x.t;
    }
} a[N];
int find(int x) {
    return fa[x] == x ? x : fa[x] = find(fa[x]);
}
int main() {
    cin >> n >> m;
    // int k = 0;
    for (int i=1; i<=n; i++) fa[i] = i;
    for (int i=1; i<=m; i++) {
        cin >> a[i].x >> a[i].y >> a[i].t;
    }
    sort(a+1, a+m+1);
    int ans = 0;
    for (int i=1; i<=m; i++) {
        // fa[find(a[i].x)] = find(a[i].y);
        if (find(a[i].x) != find(a[i].y)) fa[find(a[i].x)] = find(a[i].y), ans++;
        if (ans == n-1) {
            cout << a[i].t << endl;
            return 0;
        }
    }
    cout << "-1" << endl;
    return 0;
}