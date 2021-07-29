#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int a[] = {10,1,35,61,89,36,55,99,76};
    for (int i=0; i<9-1; i++) {
        int min = i;
        for (int j=i+1; j<9; j++) {
            if (a[j] < a[min]) min = j;
        }
        swap(a[min], a[i]);
    }
    // for (int i=0; i<9-1; i++) {
    //     for (int j=i+1; j<9; j++) {
    //         if (a[i] < a[j]) {
    //             swap(a[i], a[j]);
    //         }
    //     }
    // }
    for (int i=0; i<9; i++) cout << a[i] << " ";
    cout << endl;
    return 0;
}