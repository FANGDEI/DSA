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
void DFS(int x) {
    if (vis[x]) return ;
    vis[x] = true;
    for (int i=head[x]; ~i; i=edge[i].next) {
        if (!vis[edge[i].to]) {
            DFS(edge[i].to);
            // To do something...
        }
    }
}

int main() {
    memset(head, -1, sizeof(head));
    DFS(1);
    return 0;
}