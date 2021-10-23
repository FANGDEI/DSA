/*
 * @Author: FANG
 * @Date: 2021-10-23 17:59:47
 */
#include <iostream>
#include <cstdio>
using namespace std;
int n, a;
char ch;
int main() {
    cin >> n;
    while (n--) {
        cin >> ch >> a;
        if (ch == 'M') {
            printf("%.2lf\n", a * 1.0 / 1.09);
        } else {
            printf("%.2lf\n", a * 1.09);
        }
        getchar();
    }
    return 0;
}