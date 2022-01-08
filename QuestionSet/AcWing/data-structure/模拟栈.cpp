/*
 * @Author: FANG
 * @Date: 2022-01-08 11:40:09
 */
#include <iostream>
#include <string>

using namespace std;

const int N = 100005;
string t;
int m, s[N], n, top = -1;
int main() {
    cin >> m;
    for (int i = 0; i < m; i++) {
        cin >> t;
        if (t == "push") {
            cin >> n;
            s[++top] = n;
        } else if (t == "pop") {
            top--;
        } else if (t == "query") {
            cout << s[top] << endl;
        } else {
            if (top == -1) cout << "YES" << endl;
            else cout << "NO" << endl;
        }
    }
    return 0;
}