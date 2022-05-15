#include <iostream>
#include <string>
#include <vector>
using namespace std;
 
int main() {
    int T;
    cin >> T;
    vector<string> v;
    v.assign(1001, "");
    v[1] = "1";
    v[2] = "2";
    v[3] = "21";
    for(int i = 3; i < 1001; i++) {
        int l = v[i-3].length();
        if(v[i-3][l-1] == '1') {
            v[i] = v[i-3] + "21";
        }
        if(v[i-3][l-1] == '2') {
            v[i] = v[i-3] + "12";
        }
    }
    while(T--) {
        int n;
        cin >> n;
        cout << v[n] << endl;
    }
}