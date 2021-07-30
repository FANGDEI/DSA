//模板】并查集
#include <iostream>
#include <algorithm>
using namespace std;
const int N = 10005;
int n, m, fa[N];
int find(int x) {
    return x == fa[x] ? x : fa[x] = find(fa[x]);
}
int unionSet(int x, int y) {
    x = find(x);
    y = find(y);
    fa[x] = y;
}
int main() {
    cin >> n >> m;
    for (int i=1; i<=n; i++) fa[i] = i;
    while (m--) {
        int z, x, y;
        cin >> z >> x >> y;
        if (z == 1) {
            unionSet(x, y);
        } else if (z == 2) {
            if (find(x) == find(y)) cout << "Y" << endl;
            else cout << "N" << endl;
        }
    }
    return 0;
}