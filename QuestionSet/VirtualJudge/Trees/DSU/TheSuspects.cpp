/*
 * @Author: FANG
 * @Date: 2021-08-23 16:28:02
 * @LastEditTime: 2021-08-23 16:41:39
 * @Description: https://vjudge.ppsucxtt.cn/problem/POJ-1611
 * @FilePath: \DSA\QuestionSet\VirtualJudge\Trees\DSU\TheSuspects.cpp
 */
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
#define ms(x, n) memset(x,n,sizeof(x));
typedef  long long LL;
const LL maxn = 30010;

int n, m;
int par[maxn], rak[maxn];
void init(){
    for(int i = 0; i <= n; i++)
        par[i] = i, rak[i] = 0;;
}
int findr(int x){
    if(par[x] == x) return x;
    else return par[x] = findr(par[x]);
}
bool isSame(int x, int y){
    return findr(x)==findr(y);
}
void unite(int x, int y){
    x = findr(x), y = findr(y);
    if(x == y) return;
    if(rak[x] < rak[y])
        par[x] = y;
    else{
        par[y] = x;
        if(rak[x]==rak[y]) rak[x]++;
    }
}
int main()
{
    while(cin >> n >> m, n+m){
        init();
        int k, p1, p2;
        for(int i = 1; i <= m; i++){
            cin >> k >> p1;
            for(int j = 2; j <= k; j++){
                cin >> p2;
                unite(p1, p2);
            }
        }
        int ans = 1;
        for(int i = 1; i <= n; i++)
            if(findr(par[i])==par[0] ) ans++;
        cout << ans << endl;
    }
	return 0;
}