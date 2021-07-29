#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int a[] = {10,1,35,61,89,36,55,99,76};
    for (int i=1; i<9; i++) {
        int key = a[i];
        int j=i-1;
        while (j>=0 && key>a[j]) {
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = key;
    }
    for (int i=0; i<9; i++) cout << a[i] << " ";
    cout << endl;
    return 0;
}