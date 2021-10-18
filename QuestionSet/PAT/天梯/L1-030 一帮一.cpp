/*
 * @Author: FANG
 * @Date: 2021-10-18 18:35:20
 */
#include <iostream>
#include <vector>
using namespace std;
struct STU {
	int sex;
	string name;
};
vector<STU> v;
vector<STU> v1;
vector<STU>::iterator it;
int n, len, i;
STU s;
int main() {
	cin >> n;
	for (i=0; i<n; i++) {
		cin >> s.sex >> s.name;
		v.push_back(s);
	}
	// cout << len << endl;;
	while (!v.empty()) {
		STU f;
		f = v.front();
		v.erase(v.begin());
		len = v.size();
		for (i=len-1; i>=0; i--) {
			if (f.sex != v[i].sex) break;
		}
		v1.push_back(f);
		v1.push_back(v[i]);
		v.erase(v.begin() + i);
	}
	int flag = 0;
	for (it = v1.begin(); it != v1.end(); it++) {
		flag++;
		if (flag == 1) cout << (*it).name;
		if (flag == 2) {
			cout << " " << (*it).name << endl;
			flag = 0;
		}
	}
	return 0;
}