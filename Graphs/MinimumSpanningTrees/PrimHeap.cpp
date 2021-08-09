#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;
#define INF 0x4f4f4f4f
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
priority_queue<pair<int, int> > q;
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
    q.push(make_pair(0, 1));
    while (!q.empty()) {
        int x = q.top().second;
        int y = -q.top().first;
        q.pop();
        if (vis[x]) continue; // 懒惰删除
        vis[x] = true;
        res += y;
        for (int i=head[x]; ~i; i=edge[i].next) {
            if (dis[edge[i].to] > edge[i].w) {
                dis[edge[i].to] = edge[i].w;
                q.push(make_pair(-dis[edge[i].to], edge[i].to)); // priority_queue默认大根堆
            }
        }
    }
    for (int i=1; i<=n; i++) if (dis[i] == INF) { cout << "orz" << endl; return 0;}
    cout << res << endl;
    return 0;
}