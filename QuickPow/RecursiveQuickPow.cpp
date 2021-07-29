#include <iostream>
using namespace std;

int quickPow(int a, int n) {
    if (n == 0) return 1;
    else if (n % 2 == 1) return quickPow(a, n - 1) * a;
    else {
        int tmp = quickPow(a, n / 2); // tmp历史变量必须要 quickPow(a, n / 2) * quickPow(a, n / 2)会计算两次
                                        //时间复杂度变为O(n)
        return tmp * tmp;
    }
}

typedef long long ll;
// 计算结果太大 通常会对一个数取模 MOD
// 对于大数据 步步取模
#define MOD 1000000007
ll QuickPow(ll a, ll n) {
    if (n == 0) return 1;
    else if (n % 2 == 1) return QuickPow(a, n - 1) % MOD;
    else {
        int tmp = QuickPow(a, n / 2) % MOD;
        return tmp * tmp % MOD;
    }
}

int main() {
    cout << quickPow(2, 5) << endl;
    return 0;
}