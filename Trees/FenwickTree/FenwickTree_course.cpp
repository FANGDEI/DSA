#include <bits/stdc++.h>

using namespace std;

const int N = 100;
int n, a[N], t[N];

int lowbit(int x) {
    return x & -x;
}

void add(int x, int k) {
    while (x <= n) {
        t[x] += k;
        x += lowbit(x);
    }
}

int ask(int x) {
    int res = 0;
    while (x > 0) {
        res += t[x];
        x -= lowbit(x);
    }
    return res;
}

int ask(int l, int r) { // l = 3 r = 6
    return ask(r) - ask(l);
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        add(i, a[i]);
    }
    cout << ask(3) << " " << ask(6) << endl;
    cout << ask(3, 6) << endl;
    return 0;
}