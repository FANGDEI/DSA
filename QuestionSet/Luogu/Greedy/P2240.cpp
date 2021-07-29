// 部分背包问题
#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
int T, N;
struct gold {
    int weight, value;
    double valueratio;
    bool operator<(const gold x) {
        return this->valueratio < x.valueratio;
    }
} a[105];
int main() {
    cin >> N >> T;
    for (int i=0; i<N; i++) {
        cin >> a[i].weight >> a[i].value;
        a[i].valueratio = 1.0 * a[i].value / a[i].weight;
    }
    sort(a, a+N);
    // for (int i=0; i<N; i++) cout << a[i].valueratio << " "; cout << endl;
    double ans = 0;
    for (int i=N; i>=0; i--) {
        if (T >= a[i].weight) {
            T -= a[i].weight;
            ans += a[i].value;
        } else if (T < a[i].weight) {
            ans += (1.0 * T) / a[i].weight * a[i].value;
            T -= T;
        }
        if (T == 0) break;
    }
    printf("%.2lf\n", ans);
    return 0;
}