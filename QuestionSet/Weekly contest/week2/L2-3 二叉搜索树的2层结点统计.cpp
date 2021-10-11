/*
 * @Author: FANG
 * @Date: 2021-08-01 08:54:11
 */
/**
 * 二叉搜索树或者是一棵空树,或者是具有下列性质的二叉树:若它的左子树不空，则左子树上所有结点的值均小于或等于它的根结点的值:
 * 若它的右子树不空，则右子树上所有结点的值均大于它的根结点的值；它的左、右子树也分别为二叉搜索树。
 * 将一系列数字按给定顺序插入一棵初始为空的二叉搜索树，你的任务是统计结果树中最下面 2 层的结点数。
 * 输入格式：输入在第一行给出一个正整数 N (≤1000)，为插入数字的个数。第二行给出 N 个 [−1000,1000] 区间内的整数。
 * 数字间以空格分隔。
 * 输出格式：在一行中输出最下面 2 层的结点总数。
 * 输入样例：9 25 30 42 16 20 20 35 -5 28 输出样例：6
 */

// 数组存不下树
#include <iostream>
#include <algorithm>
using namespace std;
const int NIF = 0x3f3f3f3f;
int n, t, res;
struct Tree {
    int val;
    int height;
    Tree *lchild, *rchild;
    Tree() {
        val = NIF;
        height = -1;
        lchild = rchild = nullptr;
    }
    Tree(int _val, int _height) {
        val = _val;
        height = _height;
        lchild = rchild = nullptr;
    }
};
void insert(Tree *root, int key, int height) {
    if (key > root->val) {
        if (root->rchild == nullptr) {
            root->rchild = new Tree(key, height);
        } else {
            insert(root->rchild, key, height + 1);
        }
    } else {
        if (root->lchild == nullptr) {
            root->lchild = new Tree(key, height);
        } else {
            insert(root->lchild, key,height + 1);
        }
    }
}
int getDeepth(Tree *root) {
    if (root == nullptr) return 0;
    if (root->lchild == nullptr && root->rchild == nullptr) return 1;
    return max(getDeepth(root->lchild), getDeepth(root->rchild)) + 1;
}
void preOrder(Tree *root, int deep) {
    if (root != nullptr) {
        if (root->height == deep - 1 || root->height == deep - 2) res++;
        preOrder(root->lchild, deep);
        preOrder(root->rchild, deep);
    }
}
int main() {
    cin >> n;
    cin >> t;
    Tree *root = new Tree(t, 0);
    for (int i = 1; i < n; i++) {
        cin >> t;
        insert(root, t, 1);
    }
    int deep = getDeepth(root);
    // cout << deep << endl;
    preOrder(root, deep);
    cout << res << endl;
    return 0;
}
// 数组做法 5分
/*
    #include <iostream>
    #include <cstring>
    #include <cmath>
    using namespace std;
    const int N = 1e7 + 5;
    const int NIF = 0x3f3f3f3f;
    int n, tree[N];

    void insert(int root, int key) {
        if (tree[root] == NIF) {
            tree[root] = key;
            return ;
        }
        if (tree[root] <= key) {
            insert(root << 1 | 1, key);
        } else if (tree[root] > key) {
            insert(root << 1, key);
        }
    }

    int getDeep(int root) {
        if (tree[root] == NIF) return 0;
        if (tree[root << 1] == NIF && tree[root << 1 | 1] == NIF) return 1;
        return max(getDeep(root << 1), getDeep(root << 1 | 1)) + 1;
    }

    int main() {
        cin >> n;
        memset(tree, NIF, sizeof(tree));
        for (int i = 0; i < n; i++) {
            int t;
            cin >> t;
            insert(1, t);
        }
        int deep = getDeep(1) - 2;
        if (deep <= 0) {
            int res = 0;
            for (int i = 1; i < 4; i++) if (tree[i] != NIF) res++;
            cout << res << endl;
            return 0;
        }
        int s = pow(2, deep), e = s + s + pow(2, deep + 1);
        int res = 0;
        for (int i = s; i < e; i++) if (tree[i] != NIF) res++;
        cout << res << endl;
        return 0;
    }
*/