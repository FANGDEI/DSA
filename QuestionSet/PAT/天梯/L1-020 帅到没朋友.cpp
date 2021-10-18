/*
 * @Author: FANG
 * @Date: 2021-10-18 17:51:13
 */
#include <iostream>
using namespace std;
int fa[100000] = {0};
int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int k;
        cin >> k;
        if (k == 1) {
            int t;
            cin >> t; // 不能直接跳过
            continue;
        }
        for (int j = 0; j < k; j++) {
            int t;
            cin >> t;
            fa[t] = 1;
        }
    }
    int m;
    cin >> m;
    bool ok = true;
    for (int i = 0; i < m; i++) {
        int t;
        cin >> t;
        if (fa[t] == 0) if (ok) printf("%05d", t), ok = false; else printf(" %05d", t), fa[t] = 1;
    }
    if (ok) printf("No one is handsome\n");
    return 0;
}