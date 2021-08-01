//负进制转换
#include <iostream>
#include <cstdio>
#include <stack>
using namespace std;
stack<char> s;
int main() {
    int n, m;
    cin >> n >> m;
    int ans = n;
    while (n) {
        int k = n % m;
        if (k<0) {
            k -= m;
            n += m;
        }
        if (k>=10) {
            k = 'A'-'0'+k-10;
        }
        s.push(k+'0');
        n=n/m;
    }
    printf("%d=", ans);
    while (!s.empty()) {
        cout << s.top();
        s.pop();
    }
    printf("(base%d)", m);
    return 0;
}