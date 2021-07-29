//采药
#include <iostream>
#include <algorithm>
using namespace std;
int T, M;
int dp[1005], t[105], v[105];
int main() {
    cin >> T >> M;
    for (int i=1; i<=M; i++) cin >> t[i] >> v[i];
    for (int i=1; i<=M; i++) {
        for (int j=T; j>=t[i]; j--) {
            dp[j] = max(dp[j], dp[j-t[i]]+v[i]);
        }
    }
    cout << dp[T] << endl;
    return 0;
}