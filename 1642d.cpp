#include <iostream>
#include <vector>
using namespace std;
 
int find_x(vector<int> &v, int l, int r, int x) {
    for(int i = l; i <= r; i++) {
        if(v[i] == x) {
            return i;
        }
    }
    return -1;
}
 
int main() {
    int T;
    cin >> T;
    while(T--) {
        int n;
        cin >> n;
        vector<int> v;
        for(int i = 0; i < n; i++) {
            int x;
            cin >> x;
            v.push_back(x);
        }
        vector<int> tandems;
        vector<pair<int, int>> ops;
        int i = 0;
        int pos = 0;
        int ff = 1;
        while(i < n) {
            int j = find_x(v, i+1, n-1, v[i]);
            if(j == -1) {
                cout << -1 << endl;
                ff = 0;
                break;
            }
            tandems.push_back((j-i)*2);
            vector<int> toAdd;
            for(int k = i+1; k < j; k++) {
                toAdd.push_back(v[k]);
                ops.push_back({pos+j+k-i, v[k]});
            }
            for(int k = 0; k < toAdd.size(); k++) {
                v[i+2+k] = toAdd[toAdd.size()-k-1];
            }
            i += 2;
            pos += (j-i)*2 + 2;
        }
        if(ff) {
            cout << ops.size() << endl;
            for(int k = 0; k < ops.size(); k++) {
                cout << ops[k].first << " " << ops[k].second << endl;
            }
            cout << tandems.size() << endl;
            for(int k = 0; k < tandems.size(); k++) {
                cout << tandems[k] << " ";
            }
            cout << endl;
        }
    }
}