/*
 * @Author: FANG
 * @Date: 2022-02-21 21:03:45
 */
#include <iostream>
#include <vector>

using namespace std;

struct Edge {
  int u, v;
};

int n, m;
vector<Edge> e;
vector<bool> vis;

bool find_edge(int u, int v) {
  for (int i = 1; i <= m; ++i) {
    if (e[i].u == u && e[i].v == v) {
      return true;
    }
  }
  return false;
}

void dfs(int u) {
  if (vis[u]) return;
  vis[u] = true;
  for (int i = 1; i <= m; ++i) {
    if (e[i].u == u) {
      cout << e[i].u << "----->" << e[i].v << endl;
      dfs(e[i].v);
    }
  }
}

int main() {
  cin >> n >> m;

  vis.resize(n + 1, false);
  e.resize(m + 1);

  for (int i = 1; i <= m; ++i) cin >> e[i].u >> e[i].v;

  dfs(1);

  return 0;
}