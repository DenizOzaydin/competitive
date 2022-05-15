#include <iostream>
#include <vector>
using namespace std;
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin >> T;
    while(T--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> v;
        for(int i = 0; i < n; i++) {
            vector<int> temp;
            string str;
            cin >> str;
            for(int j = 0; j < m; j++) {
                int x;
                if(str[j] == '0') {
                    x = 0;
                }
                else {
                    x = 1;
                }
                temp.push_back(x);
            }
            v.push_back(temp);
        }
        bool xxx = true;
        for(int i = 1; i < n; i++) {
            for(int j = 1; j < m; j++) {
                int c = v[i][j] + v[i-1][j] + v[i-1][j-1] + v[i][j-1];
                if(c == 3) {
                    xxx = false;
                }
            }
        }
        if(xxx) {
            cout << "Yes" << endl;
        }
        else {
            cout << "No" << endl;
        }
    }
}