/*
7-18 Alan的"质因数"
算数基本定理，又称唯一分解定理，算术基本定理可表述为：任何一个大于1的自然数 N,如果N不为质数，那么N可以唯一分解成有限个质数的乘积。
朴素的质因子分解算法就是利用了算数基本定理，依次枚举p判断N是否包含素因子p。
Alan最近对于质因数分解产生了浓厚的兴趣。
Alan定义了一个函数 F(x)，它表示将 x 做质因数分解后得到的数字从小到大升序排列，然后将其“拼接”成一个大整数。 例如1500 = 2 * 2 * 3 * 5 * 5 * 5, F(1500) = 223555。
Alan现在给你一个数字N，请你求出 F(N) 的值。 由于这个结果可能非常大，所以你只用告诉Alan最终答案对 10^9+7 取余数的结果即可。
输入格式:
仅一行一个正整数 n(2≤n≤10^7)
输出格式:
仅一行，表示答案对 10^9+7 取余数的结果
*/

#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <string>
#include <vector>
using namespace std;
vector<int> v;
int prime[10000007], k = 0;
bool a[10000007];
void Sieve() {
    for (int i=2; i<=10000007; i++) {
        if (a[i] == 0) prime[++k] = i;
        for (int j=1; j<=k&&i*prime[j]<=10000007; j++) {
            a[i * prime[j]] = 1;
            if (i%prime[j] == 0) break;
        }
    }
}
void Ans(int n) {
	for (int i = 1; i <= k; i++) {
		double m = (double)n / prime[i];
		if (m - int(m) != 0) continue;
		if (a[n / prime[i]] == 0 && (n / prime[i]) >= 2) { //都为素数加入v
            v.push_back(n / prime[i]);
			v.push_back(prime[i]);
			return;
		}
		else {
			v.push_back(prime[i]);
			Ans(n / prime[i]); //递归
			return;
		}
	}
}
int main() {
    Sieve();
	long long n;
	cin >> n;
    Ans(n);
    string s = "";
    sort(v.begin(), v.end());
    for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
        s += to_string(*it);
    }
    double res = atof(s.c_str());
    long long ans = (long long)res;
    cout << ans % 1000000007 << endl;
	return 0;
}
