struct Edge {
    int to;
    int w;
    int next;
} edge[MAX_M];
int head[MAX_N], cnt;
bool vis[MAX_N];
void add(int u, int v, int w) {
    edge[++cnt].to = v;
    edge[cnt].w = w;
    edge[cnt].next = head[u];
    head[u] = cnt;
}
void BFS(int x) {
    queue<int> q;
    q.push(x);
    vis[x] = true;
    while (!q.empty()) {
        int f = q.front();
        q.pop();
        for (int i=head[f]; ~i; i=edge[i].next) {
            if (!vis[edge[i].to]) {
                q.push(edge[i].to);
                vis[edge[i].to] = true;
                // To do something...
            }
        }
    }
}

int main() {
    memset(head, -1, sizeof(head));
    BFS(1);
    return 0;
}