/*
 * @Author: FANG
 * @Date: 2022-01-07 14:16:16
 */
#include <iostream>

using namespace std;

const int N = 100005;
// head 头节点下标
// idx当前操作节点的下标
int e[N], ne[N], head, idx;

void init() {
    head = -1;
    idx = 0;
}

void addHead(int x) {
    e[idx] = x;
    ne[idx] = head;
    head = idx;
    idx++;
}

void add(int k, int x) {
    e[idx] = x;
    ne[idx] = ne[k];
    ne[k] = idx;
    idx++;
}

void deleteVal(int k) {
    ne[k] = ne[ne[k]];
}

int main() {
    int m, x, k;
    cin >> m;
    init();
    for (int i = 0; i < m; i++) {
        char op;
        cin >> op;
        if (op == 'H') {
            cin >> x;
            addHead(x);
        } else if (op == 'D') {
            cin >> k;
            if (k == 0) head = ne[head];
            else deleteVal(k - 1);
        } else {
            cin >> k >> x;
            add(k - 1, x);
        }
    }
    for (int i = head; i != -1; i = ne[i]) cout << e[i] << " ";
    cout << endl;
    return 0;
}