#include <iostream>
#include <algorithm>
using namespace std;
const int N = 5005;
const int M = 2e5 + 5;
int n, m;
struct Edge {
    int x, y, w;
    bool operator < (const Edge x) {
        return this->w < x.w;
    }
} edge[M];
int fa[N];
// bool vis[N];
int find(int x) {
    return x == fa[x] ? x : fa[x] = find(fa[x]);
}
// bool cmp(Edge a, Edge b) {
//     return a.w < b.w;
// }
int main() {
    cin >> n >> m;
    for (int i=1; i<=m; i++) {
        cin >> edge[i].x >> edge[i].y >> edge[i].w;
    }
    for (int i=1; i<=n; i++) fa[i] = i;
    sort(edge + 1, edge + m + 1);
    long long ans = 0, r = 0;
    for (int i=1; i<=m; i++) {
        if (find(edge[i].x) != find(edge[i].y)) {
            fa[find(edge[i].x)] = find(edge[i].y);
            r++;
            ans += edge[i].w;
        }
    }
    if (r != n - 1) cout << "orz" << endl;
    else cout << ans << endl;
    return 0;
}