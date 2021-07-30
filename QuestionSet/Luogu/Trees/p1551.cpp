//亲戚
#include <iostream>
using namespace std;
int fa[5005];
int n, m, p;
int find(int x) {
    return fa[x] == x ? x : fa[x] = find(fa[x]);
}
int main() {
    cin >> n >> m >> p;
    for (int i=1; i<=n; i++) fa[i] = i;
    while (m--) {
        int x, y;
        cin >> x >> y;
        fa[find(x)] = find(y);
    }
    while (p--) {
        int x, y;
        cin >> x >> y;
        if (find(x) == find(y)) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    return 0;
}