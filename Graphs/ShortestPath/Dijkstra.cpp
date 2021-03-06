#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9 + 5;
const int N = 1e4 + 5;
const int M = 500005;
int n, m, s, cnt;
bool vis[N];
int head[N], dis[N];
struct Edge {
    int to;
    int w;
    int next;
} edge[M];
void add(int u, int v, int w) {
    edge[++cnt].to = v;
    edge[cnt].w = w;
    edge[cnt].next = head[u];
    head[u] = cnt;
}
int main() {
    memset(head, -1, sizeof(head));
    cin >> n >> m >> s;
    for (int i=1; i<=m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        add(u, v, w);
    }
    for (int i=1; i<=n; i++) dis[i] = INF;
    dis[s] = 0;
    for (int i=1; i<=n; i++) {
        int m = INF, x = 0;
        for (int j=1; j<=n; j++) if (!vis[j] && dis[j] < m) m = dis[j], x = j;
        vis[x] = true;
        for (int k=head[x]; ~k; k=edge[k].next) dis[edge[k].to] = min(dis[edge[k].to], dis[x] + edge[k].w);
    }
    for (int i=1; i<=n; i++) if (dis[i] != INF) cout << dis[i] << " "; else cout << 0x7fffffff << " ";
    cout << endl;
    return 0;
}