/*
 * @Author: FANG
 * @Date: 2021-09-27 14:07:22
 */
#include <iostream>
using namespace std;
double a[1005], b[1005];
int k, t;
int main() {
    cin >> k;
    for (int i = 0; i < k; i++) {
        cin >> t;
        cin >> a[t];
    }
    cin >> k;
    for (int i = 0; i < k; i++) {
        cin >> t;
        cin >> b[t];
    }
    int num = 0;
    for (int i = 0; i < 1005; i++) {
        a[i] = a[i] + b[i];
        if (a[i] != 0) num++;
    }
    cout << num;
    int cnt = 0;
    for (int i = 1000; i >=0; i--) {
        if (a[i] != 0) printf(" %d %.1lf", i, a[i]);
    }
    return 0;
}