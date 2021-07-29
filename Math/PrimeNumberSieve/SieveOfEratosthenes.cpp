#include <iostream>

using namespace std;
#define MAX 10000005 // 不超过一亿

int a[MAX], prime[MAX];
int main() {
    int k = 0;
    for (int i=2; i<=100; i++) {
        if (a[i] == 0) {
            for (int j=2; i*j<=100; j++) {
                a[i * j] = 1;
            }
            prime[++k] = i;
        }
    }
    for (int i=1; i<=k; i++) cout << prime[i] << " ";
    return 0;
}