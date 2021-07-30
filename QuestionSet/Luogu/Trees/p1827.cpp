//[USACO3.4]美国血统 American Heritage
#include <iostream>
using namespace std;
string preorder, inorder;
void ansFunction(int x, int y, int p, int q) {
    if (x > y || p > q) return ;
    int m = inorder.find(preorder[x]);
    ansFunction(x+1, x+m-p, p, m-1);
    ansFunction(x+m-p+1, y, m+1, q);
    cout << preorder[x];
}
int main() {
    cin >> inorder >> preorder;
    int l = preorder.length()-1;
    ansFunction(0,l,0,l);
    cout << endl;
    return 0;
}