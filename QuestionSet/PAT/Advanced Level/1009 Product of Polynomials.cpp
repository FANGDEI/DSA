/*
 * @Author: FANG
 * @Date: 2021-08-01 08:54:11
 */
#include <iostream>
using namespace std;
double a[1005], b[1005], c[1005 * 2];
int k, t;
int main() {
    cin >> k;
    for (int i = 0; i < k; i++) {
        cin >>  t;
        cin >> a[t];
    }
    cin >> k;
    for (int i = 0; i < k; i++) {
        cin >> t;
        cin >> b[t];
    }
    for (int i = 0; i < 1005; i++) {
        for (int j = 0; j < 1005; j++) {
            c[i + j] += a[i] * b[j];
        }
    }
    int cnt = 0;
    for (int i = 0; i < 1005 * 2; i++) {if (c[i]) cnt++;}
    // int flag = 0;
    printf("%d", cnt);
    for (int i = 1005 * 2 - 1; i >= 0; i--) {
        if (c[i] != 0) {
            // if (!flag) {printf("%d %.1lf", i, c[i]); flag = 1;}
            printf(" %d %.1lf", i, c[i]);
        }
    }
    putchar('\n');
    return 0;
}