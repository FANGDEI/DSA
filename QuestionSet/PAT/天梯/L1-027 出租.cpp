/*
 * @Author: FANG
 * @Date: 2021-10-18 18:29:38
 */
#include <iostream>
#include <set>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
set<char> s;
int main() {
    char num[11];
    cin >> num;
    for (int i=0; i<11; i++) s.insert(num[i]);
    char arr[11];
	int index[11], n = 0, nn = 0, i, j;
    set<char>::reverse_iterator it;
	for (it = s.rbegin(); it != s.rend(); it++) arr[n++] = *it;
	for (i=0; i<11; i++) {
		for (j=0; j<n; j++) {
			if (num[i] == arr[j]) break;
		}
		index[nn++] = j;
	}
//	int[] arr = new int[]{8,3,2,1,0};
//	int[] index = new int[]{3,0,4,3,1,0,2,4,3,4,4};
	cout << "int[] arr = new int[]{";
	for (i = 0; i<n; i++) {
		if (i+1==n) printf("%c};\n", arr[i]);
		else printf("%c,", arr[i]);
	}
	cout << "int[] index = new int[]{";
	for (i=0; i<11; i++) {
		if (i+1==11) printf("%d};\n", index[i]);
		else printf("%d,", index[i]);
	}
	
    return 0;
}