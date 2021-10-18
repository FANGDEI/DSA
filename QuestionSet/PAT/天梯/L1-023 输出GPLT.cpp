/*
 * @Author: FANG
 * @Date: 2021-10-18 18:07:40
 */
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    int f = 0;
    string s;
    cin >> s;
    int g = 0;
    int p = 0;
    int l = 0;
    int t = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == 'G' || s[i] == 'g')
        {
            g++;
        }
        if (s[i] == 'P' || s[i] == 'p')
        {
            p++;
        }
        if (s[i] == 'L' || s[i] == 'l')
        {
            l++;
        }
        if (s[i] == 'T' || s[i] == 't')
        {
            t++;
        }
    }
    int sum = g + p + l + t;
    for (int i = 0; i < sum; i++)
    {
        if (g != 0)
        {
            cout << 'G';
            g--;
        }
        if (p != 0)
        {
            cout << 'P';
            p--;
        }
        if (l != 0)
        {
            cout << 'L';
            l--;
        }
        if (t != 0)
        {
            cout << 'T';
            t--;
        }
    }
    return 0;
}
