/*
 * @Author: FANG
 * @Date: 2021-10-18 13:17:42
 */
#include <iostream>
#include <algorithm>
using namespace std;
int N, V;
int s[105], v[105], w[105], f[105];
int main() {
    cin >> N >> V;
    for (int i=1; i<=N; i++) cin >> v[i] >> w[i] >> s[i];
    for (int i=1; i<=N; i++) {
        for (int ith=1; ith<=s[i]; ith++) {
            for (int j=V; j>=v[i]; j--) {
                f[j] = max(f[j], f[j-v[i]]+w[i]);
            }
            // f[j] = max(f[j], f[j-v[i]]+w[i]);
        }
    }
    cout << f[V] << endl;
    return 0;
}