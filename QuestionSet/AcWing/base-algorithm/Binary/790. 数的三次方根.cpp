/*
 * @Author: FANG
 * @Date: 2021-10-28 23:43:20
 */
#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
double n;
bool check(double x) {
    if (x * x * x >= n) return true;
    return false;
}
int main() {
    cin >> n;
    double l = -10005, r = 10005;
    while (r - l > 1e-8) {
        double mid = (l + r) / 2;
        if (check(mid)) r = mid;
        else l = mid;
    }
    printf("%.6lf", l);
    return 0;
}