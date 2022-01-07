/*
 * @Author: FANG
 * @Date: 2022-01-07 14:51:01
 */
#include<iostream>
using namespace std;
const int N=1e5+10;
int e[N], l[N], r[N], idx;

void insert(int a, int x){
    e[idx]=x;
    l[idx]=a, r[idx]=r[a];
    l[r[a]]=idx, r[a]=idx++;
}
void remove (int a){
    l[r[a]]=l[a];
    r[l[a]]=r[a];
}
int main(){
    r[0]=1, l[1]=0, idx=2;
    int n;
    cin>>n;
    while(n--){
        string op;
        int k,x;
        cin>>op;
        if(op=="L"){
            cin>>x;
            insert(0, x);
        }else if(op=="R"){
            cin>>x;
            insert(l[1], x);
        }else if(op=="D"){
            cin>>k;
            remove(k+1);
        }else if(op=="IL"){
            cin>>k>>x;
            insert(l[k+1], x);
        }else if(op=="IR"){
            cin>>k>>x;
            insert(k+1, x);
        }
    }
    for(int i=r[0];i!=1;i=r[i]) cout<<e[i]<<' ';
}