/*
 * @Author: FANG
 * @Date: 2021-10-23 17:59:08
 */
#include <stdio.h>

int main() {
    int a, b;
    scanf("%d %d", &a, &b);
    printf("%d/", a);
    if (b < 0) printf("(%d)=", b); else printf("%d=", b);
    if (b == 0) printf("Error");
    else printf("%.2lf", a * 1.0 / b);
    return 0;
}