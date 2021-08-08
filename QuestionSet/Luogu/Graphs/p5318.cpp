//P5318 【深基18.例3】查找文献
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
// const int N = 10;
// const int M = 1e6 + 5;
struct Edge {
    int u, v;
    // bool operator < (const Edge x) {
    //     if (this->v == x.v) return this->u < x.u;
    //     return this->v < x.v;
    // }
};
vector<Edge> s;
vector<int> e[N];
int n, m;
bool vis[N];
bool cmp(Edge x, Edge y) {
    if (x.v == y.v) return x.u < y.u;
    return x.v < y.v;
}
void DFS(int x) {
    // if (vis[x]) return ;
    vis[x] = true;
    cout << x << " ";
    for (int i=0; i<e[x].size(); i++) {
        if (!vis[s[e[x][i]].v]) DFS(s[e[x][i]].v);
    }
}
void BFS(int x) {
    queue<int> q;
    q.push(x);
    vis[x] = true;
    while (!q.empty()) {
        int f = q.front();
        q.pop();
        for (int i=0; i<e[f].size(); i++) {
            if (!vis[s[e[f][i]].v]) {
                q.push(s[e[f][i]].v);
                cout << s[e[f][i]].v << " ";
                vis[s[e[f][i]].v] = true;
            }
        }
    }
}
int main() {
    cin >> n >> m;
    for (int i=1; i<=m; i++) {
        Edge ed;
        cin >> ed.u >> ed.v;
        s.push_back(ed);
    }
    sort(s.begin(), s.end(), cmp);
    for (int i=0; i<m; i++) {
        e[s[i].u].push_back(i);
    }
    DFS(1);
    cout << endl;
    memset(vis, false, sizeof(vis));
    cout << "1" << " ";
    BFS(1);
    return 0;
}