//最长公共子序列 50
/*
摘自[https://www.luogu.com.cn/blog/blue/solution-p1439]
关于为什么可以转化成LIS问题，这里提供一个解释。
A:3 2 1 4 5
B:1 2 3 4 5
我们不妨给它们重新标个号：把3标成a,把2标成b，把1标成c……于是变成：
A: a b c d e
B: c b a d e
这样标号之后，LCS长度显然不会改变。但是出现了一个性质：
两个序列的子序列，一定是A的子序列。而A本身就是单调递增的。
因此这个子序列是单调递增的。
换句话说，只要这个子序列在B中单调递增，它就是A的子序列。
哪个最长呢？当然是B的LIS最长。
自此完成转化。
*/
#include <iostream>
#include <algorithm>
using namespace std;
int n;
const int N = 100000 + 5;
int a[N], b[N], f[1001][1001];
int main() {
    cin >> n;
    for (int i=1; i<=n; i++) cin >> a[i];
    for (int i=1; i<=n; i++) cin >> b[i];
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            if (a[i] == b[j]) f[i][j] = f[i-1][j-1] + 1;
            else f[i][j] = max(f[i-1][j], f[i][j-1]);
        }
    }
    cout << f[n][n] << endl;
    return 0;
}