/*
 * @Author: FANG
 * @Date: 2021-10-14 18:42:44
 */
#include <iostream>
using namespace std;
int main() {
    int a, b;
    cin >> a >> b;
    int sum = 0;
    int cnt = 0;
    for (int i = a; i <= b; i++) {
        sum += i;
        cnt++;
        if (cnt % 5 != 0) {
            printf("%5d", i);
        } else {
            printf("%5d\n", i);
        }
    }
    if (cnt % 5 != 0) putchar('\n');
    printf("Sum = %d\n", sum);
    return 0;
}