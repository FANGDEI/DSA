/*
 * @Author: FANG
 * @Date: 2021-10-14 18:44:47
 */
#include <stdio.h>
#include <math.h>
int main() {
    int n;
    scanf("%d", &n);
    int res = 1;
    for (int i = 1; i <= n; i++) res *= 2;
    printf("2^%d = %d", n, res);
    return 0;
}