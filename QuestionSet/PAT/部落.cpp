#include <iostream>
#include <set>
#include <algorithm>
using namespace std;
set<int> s;
int fa[10005];
// int fa[15];
int find(int x) {
    // if (fa[x] == x) return fa[x];
    // else {
    //     fa[x] = find(fa[x]);
    //     return fa[x];
    // }
	return x == fa[x] ? x : fa[x] = find(fa[x]);
}
// void unionSet(int x, int y) {
//     x = find(x);
//     y = find(y);
//     fa[x] = y;
// }
int n, ans, m;
int main() {
    for (int i=1; i<=10005; i++) fa[i] = i;
    cin >> n;
//     m = n;
    while (n--) {
        int k;
        cin >> k;
        int first;
        cin >> first;
		ans = max(ans, first);
		first = find(first);
//         fa[first] = first;
		// first = find(first);
        // ans = max(ans, first);
//         if (fa[first]) unionSet(fa[first], first);
//         else fa[first] = first;
        for (int i=0; i<k-1; i++) {
            int t;
            cin >> t;
            ans = max(ans, t);
            fa[find(t)] = first;
        }
    }
    int ans1=0;
    // for (int i=1; i<=ans; i++) find(fa[i]);
    for (int i=1; i<=ans; i++) ans1 = find(fa[i]),s.insert(ans1);
    cout << ans << " " << s.size() << endl;
//     int m;
    cin >> m;
    while (m) {
        int a, b;
        cin >> a >> b;
        if (m == 1) {
            if (find(a) == find(b)) cout << "Y";
            else cout << "N";
        } else 
            if (find(a) == find(b)) cout << "Y" << endl;
            else cout << "N" << endl;
        m--;
    }
    return 0;
}