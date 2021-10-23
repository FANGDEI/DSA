/*
 * @Author: FANG
 * @Date: 2021-10-21 20:51:33
 */
#include <iostream>
#include <algorithm>
using namespace std;
int f[1005];
int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int k;
        cin >> k;
        for (int j = 0; j < k; j++) {
            int t;
            cin >> t;
            f[t]++;
        }
    }
    int index = 1;
    for (int i = 1; i < 1005; i++) if (f[i] >= f[index]) index = i;
    cout << index << " " << f[index] << endl;
    return 0;
}