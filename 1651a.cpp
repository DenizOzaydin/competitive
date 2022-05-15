#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
 
int main() {
    int T;
    cin >> T;
    while(T--) {
        int n;
        cin >> n;
        int p = 1;
        for(int i = 0; i < n; i++) {
            p *= 2;
        }
        cout << p-1 << endl;
    }
}