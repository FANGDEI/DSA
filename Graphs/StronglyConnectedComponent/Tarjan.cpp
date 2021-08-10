#include <iostream>
#include <cstring>
#include <algorithm>
#include <stack>
using namespace std;
const int N = 1005;
int n, m;
struct Edge {
    int to;
    // int w;
    int next;
} edge[N];
int head[N], cnt, dfn[N], low[N], t;
bool vis[N];
stack<int> s;
void Tarjan(int x) {
    dfn[x] = low[x] = ++t;
    s.push(x);
    vis[x] = true;
    for (int i=head[x]; ~i; i=edge[i].next) {
        if (!dfn[edge[i].to]) {
            Tarjan(edge[i].to);
            low[x] = min(low[x], low[edge[i].to]);
        } else if (vis[edge[i].to]) {
            low[x] = min(low[x], dfn[edge[i].to]);
        }
    }
    if (low[x] == dfn[x]) {
        while (!s.empty()) {
            int top = s.top();
            s.pop();
            cout << top << " ";
            vis[top] = false;
            if (top == x) break;
        }
        cout << endl;
    }
}
int main() {
    memset(head, -1, sizeof(head));
    cin >> n >> m;
    for (int i=1; i<=m; i++) {
        int u, v;
        cin >> u >> v;
        edge[++cnt].to = v;
        edge[cnt].next = head[u];
        head[u] = cnt;
    }
    for (int i=1; i<=n; i++) {
        if (!dfn[i]) Tarjan(i);
    }
    return 0;
}