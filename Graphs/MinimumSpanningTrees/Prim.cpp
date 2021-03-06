#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
#define INF 0x3f3f3f3f
const int N = 5005;
const int M = 2e5 + 5;
struct Edge {
    int to;
    int w;
    int next;
} edge[M << 1];
int head[N << 1], cnt;
int n, m, dis[N << 1];
long long res;
bool vis[N << 1];
void add(int u, int v, int w) {
    cnt++;
    edge[cnt].to = v;
    edge[cnt].w = w;
    edge[cnt].next = head[u];
    head[u] = cnt;
}
int main() {
    memset(head, -1, sizeof(head));
    cin >> n >> m;
    for (int i=1; i<=m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        add(u, v, w);
        add(v, u, w);
    }
    memset(dis, INF, sizeof(dis));
    dis[1] = 0;
    for (int i=1; i<=n; i++) {
        int m = INF, x;
        for (int j=1; j<=n; j++) {
            if (!vis[j] && dis[j] < m) {
                m = dis[j];
                x = j;
            }
        }
        vis[x] = true;
        res += m;
        for (int j=head[x]; ~j; j=edge[j].next) {
            // dis[edge[j].to] = min(dis[edge[j].to], edge[j].w);
            if (dis[edge[j].to] > edge[j].w) dis[edge[j].to] = edge[j].w;
        }
    }
    if (res >= INF) cout << "orz" << endl;
    else cout << res << endl;
    return 0;
}