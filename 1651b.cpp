#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
int main() {
    int T;
    cin >> T;
    while(T--) {
        int n;
        cin >> n;
        vector<ll> v;
        ll c = 1;
        for(int i = 0; i < n; i++) {
            v.push_back(c);
            c *= 3;
            if(c > 1000000000) {
                break;
            }
        }
        if(v.size() == n) {
            cout << "YES" << endl;
            for(int i = 0; i < n; i++) {
                cout << v[i] << " ";
            }
            cout << endl;
        }
        else {
            cout << "NO" << endl;
        }
    }
}