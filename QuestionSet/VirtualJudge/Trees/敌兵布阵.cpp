//https://vjudge.net/problem/HDU-1166
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <string>
using namespace std;
const int N = 5e4 + 5;
int n, t, sum[N];
int lowbit(int x) {
    return x & -x;
}
void update(int i, int x) {
    while (i <= n) {
        sum[i] += x;
        i += lowbit(i);
    }
}
int ask(int i) {
    int ans = 0;
    for (int j=i; j>0; j-=lowbit(j)) ans += sum[j];
    return ans;
}
int main() {
    cin >> t;
    for (int i=1; i<=t; i++) {
        printf("Case %d:\n", i);
        memset(sum, 0, sizeof(sum));
        cin >> n;
        for (int j=1; j<=n; j++) {
            int k;
            cin >> k;
            update(j, k);
        }
        string s;
        int x, y;
        while (cin >> s && s[0] != 'E') {
            cin >> x >> y;
            if (s[0] == 'A') update(x, y);
            else if (s[0] == 'S') update(x, -y);
            else if (s[0] == 'Q') cout << ask(y) - ask(x-1) << endl;
        }
    }
    return 0;
}