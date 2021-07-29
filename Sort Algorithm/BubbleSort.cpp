#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int a[] = {10,1,35,61,89,36,55,99,76};
    for (int i=0; i<9-1; i++) {
        for (int j=0; j<9-i-1; j++) {
            if (a[j] > a[j+1]) swap(a[j], a[j+1]);
        }
    }
    for (int i=0; i<9; i++) cout << a[i] << " ";
    cout << endl;
    return 0;
}