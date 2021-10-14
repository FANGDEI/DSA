/*
 * @Author: FANG
 * @Date: 2021-10-14 18:28:43
 */
#include<bits/stdc++.h>
using namespace std;
int n,h;
char x;
int main()
{
    cin>>n>>x;
    h=sqrt((n+1)/2);
    for(int i=h;i>=1;i--)
    {
        for(int j=1;j<=h-i;j++)cout<<' ';
        for(int j=1;j<=2*i-1;j++)cout<<x;
        cout<<endl;
    }
    for(int i=2;i<=h;i++)
    {
        for(int j=1;j<=h-i;j++)cout<<' ';
        for(int j=1;j<=2*i-1;j++)cout<<x;
        cout<<endl;
    }
    cout<<n-(2*h*h-1)<<endl;
    return 0;
}