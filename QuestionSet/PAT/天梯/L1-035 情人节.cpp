/*
 * @Author: FANG
 * @Date: 2021-10-23 17:58:33
 */
#include <iostream>
#include <string>
#include <vector>
using namespace std;
vector<string> v;
int main() {
	string s;
	getline(cin, s);
	while (s[0] != '.') {
		v.push_back(s);
		getline(cin, s);
	}
	if (v.size() < 2) {
		cout << "Momo... No one is for you ..." << endl;
		return 0;
	} else if (v.size() < 14) {
		cout << v[1] << " is the only one for you..." << endl;
		return 0;
	}
	else if (v.size() >= 14) cout << v[1] << " and " << v[13] << " are inviting you to dinner..." << endl;
	return 0;
}