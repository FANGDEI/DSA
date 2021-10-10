/*
 * @Author: FANG
 * @Date: 2021-10-10 20:08:18
 * 
 * 在mod p意义下 对于一个整数a 有a*x ≡ 1 (mod p) 那么整数a, x互为乘法逆元
 * 充要条件: a存在模p的乘法逆元的充要条件是gcd(a, p) = 1 即a p互质
 *      
 * 费马小定理求逆元要求 p 为质数
 * 
 * *费马小定理:
 *      假如a是一个整数 p是一个质数
 *      1. 如果a是p的倍数 a^p ≡ a (mod p)
 *      2. 如果a不是p的倍数 a^(p - 1) ≡ 1 (mod p)
 *       => 利用费马小定理求逆元: a * a^(p - 2) ≡ 1 (mod p) => a % p * a^(p-2) % p = 1 % p
 *                                                              
 * *同余式:
 *      a ≡ b (mod p) 表示a b mod n 同余 即 (a - b) 能被 n 整除
 */
#include <iostream>
using namespace std;
typedef long long ll;

ll quickPow(ll a, ll n, ll p) {
    ll ans = 1;
    while (n) {
        if (n & 1) ans = ans % p * a % p;
        a = a % p * a % p;
        n >>= 1;
    }
    return ans;
}

ll inv(ll a, ll b) {
    return quickPow(a, p - 2, p);
}

int main() {

    return 0;
}