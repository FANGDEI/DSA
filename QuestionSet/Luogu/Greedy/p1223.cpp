//P1223 排队接水
#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
const int N = 1e3 + 5;
int n;
struct A {
    int a;
    int b;
    bool operator < (const A x) {
        return this->a < x.a;
    }
} a[N];
int main() {
    cin >> n;
    for (int i=1; i<=n; i++) cin >> a[i].a, a[i].b = i;
    sort(a+1, a+n+1);
    double sum = 0;
    for (int i=1; i<=n; i++) cout << a[i].b << " ", sum += i * a[n-i].a;
    cout << endl;
    // cout << sum / n << endl;
    printf("%.2lf", sum / n);
    return 0;
}