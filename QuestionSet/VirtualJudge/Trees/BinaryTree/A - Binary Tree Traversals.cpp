/*
 * @Author: FANG
 * @Date: 2021-11-18 19:33:23
 */
/*
 * @Author: FANG
 * @Date: 2021-08-01 08:54:11
 */
#include <iostream>

using namespace std;
const int N = 1005;
int n, in[N], pre[N], cnt = 0;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };
// [x, y] 前序 [m, n]中序
TreeNode* rebuild(int x, int y, int m, int n) {
    if (x > y || m > n) return nullptr;
    TreeNode *root = new TreeNode(pre[x]);
    int j = 0;
    for (j = m; j <= n; j++) {
        if (pre[x] == in[j]) break;
    }
//     int leftNum = j - m;
    root->left = rebuild(x + 1, x + j - m, m, j - 1);
    root->right = rebuild(x + j - m + 1, y, j + 1, n);
    return root;
}

void post(TreeNode *root) {
	if (root == NULL) return ;
	post(root->left);
	post(root->right);
	cout << root->val << " ";
    cnt++;
    if (cnt == n) cout << endl;
}

int main() {
	while (cin >> n && n) {
        cnt = 0;
        for (int i = 0; i < n; i++) cin >> pre[i];
	    for (int i = 0; i < n; i++) cin >> in[i];
	    post(rebuild(0, n - 1, 0, n - 1));
    }
	return 0;
}