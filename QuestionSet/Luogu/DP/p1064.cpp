//金明的预算方案
// #include <iostream>
// #include <algorithm>
// using namespace std;
// int n, m;
// int f[65][32000+5], t[65][3], v[65], w[65], k, T[65][3];
// int main() {
//     cin >> n >> m;
//     for (int i=1; i<=m; i++) {
//         int v1, q, p;
//         cin >> v1 >> q >> p;
//         if (p == 0) {
//             w[i] = v1;
//             v[i] = v1 * q;
//         } else {
//             t[p][0]++;
//             t[p][t[p][0]] = v1;
//             T[p][t[p][0]] = v1 * q;
//         }
//     }
//     for (int i=1; i<=m; i++) {
//         for (int j=0; j<=n; j++) {
//             f[i][j] = f[i-1][j];
//             if (j>=w[i]) f[i][j] = max(f[i][j], f[i-1][j-w[i]]+v[i]);
//             if (j>=w[i]+t[i][1]) f[i][j] = max(f[i][j], f[i-1][j-w[i]-t[i][1]]+v[i]+T[i][1]);
//             if (j>=w[i]+t[i][2]) f[i][j] = max(f[i][j], f[i-1][j-w[i]-t[i][2]]+v[i]+T[i][2]);
//             if (j>=w[i]+t[i][2]+t[i][1]) f[i][j] = max(f[i][j], f[i-1][j-w[i]-t[i][2]-t[i][1]]+v[i]+T[i][1]+T[i][2]);
//         }
//     }
//     cout << f[m][n] << endl;
//     return 0;
// }

/* 优化 */
#include <iostream>
#include <algorithm>
using namespace std;
int n, m;
int f[32000+5], t[65][3], v[65], w[65], k, T[65][3];
int main() {
    cin >> n >> m;
    for (int i=1; i<=m; i++) {
        int v1, q, p;
        cin >> v1 >> q >> p;
        if (p == 0) {
            w[i] = v1;
            v[i] = v1 * q;
        } else {
            t[p][0]++;
            t[p][t[p][0]] = v1;
            T[p][t[p][0]] = v1 * q;
        }
    }
    for (int i=1; i<=m; i++) {
        for (int j=n; j>=w[i]; j--) {
            // f[i][j] = f[i-1][j];
            /*if (j>=w[i]) */f[j] = max(f[j], f[j-w[i]]+v[i]);
            if (j>=w[i]+t[i][1]) f[j] = max(f[j], f[j-w[i]-t[i][1]]+v[i]+T[i][1]);
            if (j>=w[i]+t[i][2]) f[j] = max(f[j], f[j-w[i]-t[i][2]]+v[i]+T[i][2]);
            if (j>=w[i]+t[i][2]+t[i][1]) f[j] = max(f[j], f[j-w[i]-t[i][2]-t[i][1]]+v[i]+T[i][1]+T[i][2]);
        }
    }
    cout << f[n] << endl;
    return 0;
}