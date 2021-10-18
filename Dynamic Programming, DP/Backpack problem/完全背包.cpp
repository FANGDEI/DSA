/*
 * @Author: FANG
 * @Date: 2021-10-18 13:16:55
 */
#include <iostream>
#include <algorithm>
using namespace std;
const int Max = 1e4 + 5;
int N, V;
int f[Max], v[Max], w[Max];
int main() {
    cin >> N >> V;
    for (int i=1; i<=N; i++) cin >> v[i] >> w[i];
    for (int i=1; i<=N; i++) {
        for (int j=v[i]; j<=V; j++) {
            f[j] = max(f[j], f[j-v[i]] + w[i]);
        }
    }
    cout << f[V] << endl;
    return 0;
}