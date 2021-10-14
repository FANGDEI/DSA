/*
 * @Author: FANG
 * @Date: 2021-10-14 18:45:03
 */
#include <stdio.h>

int main() {
    int n, res = 1, ans = 0;
    scanf("%d", &n);
    for (int i = 1; i < n + 1; i++) {
        res *= i;
        ans += res;
    }
    printf("%d", ans);
    return 0;
}