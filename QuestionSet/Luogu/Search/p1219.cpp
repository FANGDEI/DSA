//P1219 [USACO1.5]八皇后 Checker Challenge
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
const int N = 15;
int n, c[N], outnum;
void DFS(int x) {
    if (x == n) {
        outnum++;
        if (outnum <= 3) {
            for (int i=0; i<n; i++) cout << c[i] + 1 << " ";
            cout << endl;
        }
        return ;
    }
    for (int i=0; i<n; i++) {
        c[x] = i;
        bool ok = true;
        for (int j=0; j<x; j++) {
            if (c[x] == c[j] || x - c[x] == j - c[j] || x + c[x] == j + c[j]) {
                ok = false;
                break;
            }
        }
        if (ok) DFS(x + 1);
    }
}
int main() {
    cin >> n;
    DFS(0);
    cout << outnum << endl;
    return 0;
}