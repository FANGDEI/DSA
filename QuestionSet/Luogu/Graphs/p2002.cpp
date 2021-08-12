//P2002 消息扩散
#include <iostream>
#include <cstring>
#include <stack>
#include <algorithm>
using namespace std;
const int N = 1e5 + 5;
const int M = 5e5 + 5;
int n, m;
bool isinstack[N];
stack<int> s;
struct Edge {
    int from;
    int to;
    int next;
} edge[M];
int dfn[N], low[N], t, cnt, head[N], num, belong[N], in[M];
void add(int u, int v) {
    edge[++cnt].from = u;
    edge[cnt].to = v;
    edge[cnt].next = head[u];
    head[u] = cnt;
}
void Tarjan(int x) {
    dfn[x] = low[x] = ++t;
    s.push(x);
    isinstack[x] = true;
    for (int i=head[x]; ~i; i=edge[i].next) {
        if (!dfn[edge[i].to]) {
            Tarjan(edge[i].to);
            low[x] = min(low[x], low[edge[i].to]);
        } else if (isinstack[edge[i].to]) low[x] = min(low[x], dfn[edge[i].to]);
    }
    if (low[x] == dfn[x]) {
        num++;
        while (!s.empty()) {
            int top = s.top();
            s.pop();
            isinstack[top] = false;
            belong[top] = num;
            if (top == x) break;
        }
    }
}
int main() {
    memset(head, -1, sizeof(head));
    cin >> n >> m;
    for (int i=1; i<=m; i++) {
        int x, y;
        cin >> x >> y;
        if (x != y) add(x, y);
    }
    for (int i=1; i<=n; i++) belong[i] = i;
    for (int i=1; i<=n; i++) if (!dfn[i]) Tarjan(i);
    for (int i=1; i<=m; i++) {
        if (belong[edge[i].from] != belong[edge[i].to]) in[belong[edge[i].to]]++;
    }
    int ans = 0;
    for (int i=1; i<=num; i++) if (!in[i]) ans++;
    cout << ans << endl;
    return 0;
}