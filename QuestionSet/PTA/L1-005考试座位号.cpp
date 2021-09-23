/*
 * @Author: FANG
 * @Date: 2021-09-23 20:13:15
 */
#include <bits/stdc++.h>
using namespace std;
struct S {
    char s[20];
    int firstPlace;
    int lastPlace;
}s[1005];
int n;
int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        scanf("%s %d %d", s[i].s, &s[i].firstPlace, &s[i].lastPlace);
    }
    int m;
    cin >> m;
    for (int i = 0; i < m; i++) {
        int t;
        cin >> t;
        for (int i = 1; i <= n; i++) {
            if (s[i].firstPlace == t) {
                cout << s[i].s << " " << s[i].lastPlace << endl;
            }
        }
    }
    return 0;
}