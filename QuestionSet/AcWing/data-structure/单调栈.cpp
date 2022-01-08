/*
 * @Author: FANG
 * @Date: 2022-01-08 12:08:27
 */
#include <iostream>
#include <stack>
using namespace std;
stack<int> sta;
int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int m;
        cin >> m;
        while (!sta.empty() && sta.top() >= m) sta.pop();
        if (sta.empty()) cout << -1 << " ";
        else cout << sta.top() << " ";
        sta.push(m);
    }
    return 0;
}