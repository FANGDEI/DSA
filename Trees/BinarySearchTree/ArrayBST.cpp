#include <iostream>
#include <algorithm>
using namespace std;
const int MAX = 1e5 + 5;
// const int MAX = 100;
const int NIL = -1; // 空
int tree[MAX];
void init() {
    for (int i=1; i<=MAX; i++) tree[i] = NIL;
}
void insert(int root, int key) {
    if (tree[root] == NIL) {
        tree[root] = key;
        return ;
    }
    if (key > tree[root]) {
        insert(root*2+1, key);
    } else {
        insert(root*2, key);
    }
}
int findMax(int root) {
    if (tree[root] == NIL) return NIL;
    while (tree[root*2+1] != NIL) {
        root = root * 2 + 1;
    }
    return tree[root];
}
int findMin(int root) {
    if (tree[root] == NIL) return NIL;
    while (tree[root*2] != NIL) {
        root = root * 2;
    }
    return tree[root];
}
void inorderTravelRecursively(int root) {
    if (tree[root] == NIL) return ;
    else {
        inorderTravelRecursively(root * 2);
        cout << tree[root] << " ";
        inorderTravelRecursively(root * 2 + 1);
    }
}
void deleteVal(int root, int x) {
    if (tree[root] == NIL) return ;
    if (tree[root] < x) deleteVal(root*2+1, x);
    else if (tree[root] > x) deleteVal(root*2, x);
    else if (tree[root*2] != NIL && tree[root*2+1] != NIL) {
        int tmp = findMax(root*2);
        tree[root] = tmp;
        deleteVal(root*2, tmp);
    } else if (tree[root*2] == NIL && tree[root*2+1] == NIL) {
        tree[root] = NIL;
    }else {
        if (tree[root*2+1] != NIL) {
            tree[root] = tree[root*2+1];
            // tree[root*2+1] = NIL;
            deleteVal(root*2+1, tree[root*2+1]);
        } else if (tree[root*2] != NIL) {
            tree[root] = tree[root*2];
            // tree[root*2] = NIL;
            deleteVal(root*2, tree[root*2]);
        }
    }
}
int main() {
    init();
    insert(1, 45);
    insert(1, 49);
    insert(1, 12);
    insert(1, 23);
    insert(1, 99);
    insert(1, 67);
    insert(1, 34);
    insert(1, 43);
    insert(1, 76);
    insert(1, 12);
    insert(1, 45);
    inorderTravelRecursively(1);
    cout << endl;
    // for (int i=1; i<=11; i++) cout << tree[i] << " ";
    cout << findMax(1) << endl;
    cout << findMin(1) << endl;
    deleteVal(1, 12);
    inorderTravelRecursively(1);
    cout << endl;
    return 0;
}