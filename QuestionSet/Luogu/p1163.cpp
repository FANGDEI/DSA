//银行贷款
#include <cstdio>
#include <cmath>
#include <iostream>
using namespace std;
double n, m, k;
bool judge(double x) {
    double total = n;
    for (int i=1; i<=k; i++) {
        total += total * x;
        total -= m;
    }
    if (total <= 0) return true;
    else return false;
}
int main() {
    cin >> n >> m >> k;
    double l = 0, r = 10;
    while (r-l > 0.0001) {
        double mid = (r + l) / 2;
        if (judge(mid)) l = mid;
        else r = mid;
    }
    printf("%.1lf\n", l*100);
    return 0;
}