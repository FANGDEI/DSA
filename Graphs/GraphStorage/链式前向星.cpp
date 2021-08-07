#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
const int N = 1e3 + 5;
struct Edge {
    int to;
    int w;
    int next;
} e[N];
int head[N], cnt;
int n, m;
void add(int u, int v, int w) {
    e[++cnt].to = v;
    e[cnt].w = w;
    e[cnt].next = head[u];
    head[u] = cnt;
}
void visit(int u) {
    for (int i=head[u]; i!=-1; i=e[i].next) {
        cout << u << " -------> " << e[i].to << " ---w: " << e[i].w << endl;
    }
}
int main() {
    memset(head, -1, sizeof(head));
    cin >> n >> m;
    while (m--) {
        int u, v, w;
        cin >> u >> v >> w;
        add(u, v, w);
    }
    visit(1);
    return 0;
}