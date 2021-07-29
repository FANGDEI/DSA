//纪念品分组
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
vector<int> v;
int w, n, ans;
// int a[30005];
int main() {
    cin >> w;
    cin >> n;
    for (int i=0; i<n; i++) {
        int t;
        cin >> t;
        v.push_back(t);
    }
    sort(v.begin(), v.end());
    while (1) {
        if (v.empty()) break;
        int f = v.front();
        v.erase(v.begin());
        ans++;
        if (!v.empty()) {
            for (int i=v.size()-1; i>=0; i--) {
                if (w-f>=v[i]) {
                    v.erase(v.begin()+i);
                    break;
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}
/* 双指针 orz orz %%%
#include<bits/stdc++.h>
using namespace std;
int W,ans=0;
int n,a[30001];
int l,r,i;
int main()
{
    scanf("%d%d",&W,&n);
    for(i=1;i<=n;i++)
      scanf("%d",&a[i]);
    sort(a+1,a+n+1);
    l=1;  r=n;
    while(l<=r)//一定要有等号。
    {
        if(a[l]+a[r]<=W)   //一定要有等号。
          l++,r--,ans++;
        else
          r--,ans++;   //贪心过程
    }
    printf("%d",ans);
    return 0;
}
*/