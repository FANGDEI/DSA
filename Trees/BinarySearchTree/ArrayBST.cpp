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
int findNum(int root) {
    if (tree[root] == NIL) return 0;
    int l = findNum(root*2);
    int r = findNum(root*2+1);
    return l + r + 1;
}
int findRoot(int root, int x) {
    if (tree[root] == NIL) return -1;
    else if (tree[root] > x) return findRoot(root*2, x);
    else if (tree[root] < x) return findRoot(root*2+1, x);
    else return root;
}
int getRank(int root, int x) {
    if (tree[root] == NIL) return 0;
    if (tree[root] == x) return findNum(root*2) + 1;
    else if (tree[root] > x) return getRank(root*2, x);
    else if (tree[root] < x) return findNum(root*2) + getRank(root*2+1, x) + 1;
}
int getX(int root, int x) {
    if (tree[root] == NIL) return -1;
    if (findNum(root*2) + 1 == x) return tree[root];
    else if (findNum(root*2) + 1 > x) return getX(root*2, x);
    else if (findNum(root*2) + 1 < x) return getX(root*2+1, x - findNum(root*2) - 1);
}
int findPredecessor(int root, int x) {
    int newRoot = findRoot(root, x);
    if (tree[newRoot*2] != NIL) return findMax(newRoot*2);
    else {
        if (tree[newRoot/2*2+1] == tree[newRoot]) return tree[newRoot/2];
        else {
            while (1) {
                newRoot /= 2;
                if (tree[newRoot/2*2+1] == tree[newRoot]) return tree[newRoot/2];
            }
        }
    }
}
int findSuccessor(int root, int x) {
    int newRoot = findRoot(root, x);
    if (tree[newRoot*2+1] != NIL) return findMin(newRoot*2+1);
    else {
        if (tree[newRoot/2*2] == tree[newRoot]) return tree[newRoot/2];
        else {
            while (1) {
                newRoot /= 2;
                if (tree[newRoot/2*2] == tree[newRoot]) return tree[newRoot/2];
            }
        }
    }
}
int main() {
    init();
    insert(1, 38);
    insert(1, 45);
    insert(1, 42);
    insert(1, 24);
    insert(1, 58);
    insert(1, 30);
    insert(1, 67);
    insert(1, 12);
    insert(1, 51);
    inorderTravelRecursively(1);
    cout << endl;
    // for (int i=1; i<=11; i++) cout << tree[i] << " ";
    cout << getRank(1, 45) << endl;
    cout << getX(1, 7) << endl;
    cout << findPredecessor(1, 30) << endl;
    cout << findSuccessor(1, 30) << endl;
    return 0;
}