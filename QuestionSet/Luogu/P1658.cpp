// 购物
#include <iostream>
#include <algorithm>
using namespace std;
int x, n;
int a[1005];
int main() {
    cin >> x >> n;
    for (int i=1; i<=n;i++) cin >> a[i];
    sort(a+1, a+n+1);
    if (a[1] != 1) {
        cout << "-1" << endl; 
        return 0;
        }
    int sum = 1;
    int ans = 1;
    while (sum < x) {
        int i;
        for (i=n; i>=1; i--) if (a[i] <= sum+1) break;
        ans++;
        sum += a[i];
    }
    cout << ans << endl;
    return 0;
}