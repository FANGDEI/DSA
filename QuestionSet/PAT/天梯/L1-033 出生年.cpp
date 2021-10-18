/*
 * @Author: FANG
 * @Date: 2021-10-18 18:39:01
 */
#include <cstdlib>
#include <iostream>
#include <cstdio>
#include <set>
#include <cstring>
using namespace std;
set<char> s;
int main() {
    int birthyear, n;
    cin >> birthyear >> n;
    int h = birthyear;
    while (1) {
    	s.insert(birthyear % 10);
    	s.insert(birthyear / 10 % 10);
    	s.insert(birthyear / 100 % 10);
    	s.insert(birthyear / 1000 % 10);
    	if (s.size() == n) break;
    	else {
    		birthyear++;
    		s.clear();
		}
	}
	printf("%d %04d", birthyear - h, birthyear);
    return 0;
}