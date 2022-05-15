#include <iostream>
#include <vector>
#include <string>
using namespace std;
 
vector<int> create_op(int a, int b, int c, int d) {
    vector<int> op;
    op.push_back(a);
    op.push_back(b);
    op.push_back(c);
    op.push_back(d);
    return op;
}
 
int value(int i, int j) {
    if((i+j)%2 == 0) {
        return 0;
    }
    else {
        return 1;
    }
}
 
int main() {
    int T;
    cin >> T;
    while(T--) {
        int n, m;
        cin >> n >> m;
        vector<string> v;
        for(int i = 0; i < n; i++) {
            string str;
            cin >> str;
            v.push_back(str);
        }
        vector<vector<int>> op;
        for(int i = n-1; i >= 0; i--) {
            for(int j = m-1; j > 0; j--) {
                if(v[i][j] == '0') {
                    op.push_back(create_op(i, j, i, j));
                }
                if(v[i][j] == '1') {
                    op.push_back(create_op(i, j-1, i, j));
                }
            }
        }
        for(int i = n-1; i > 0; i--) {
            if(v[i][0] == '0') {
                op.push_back(create_op(i, 0, i, 0));
            }
            if(v[i][0] == '1') {
                op.push_back(create_op(i-1, 0, i, 0));
            }
        }
        if(v[0][0] == '1') {
            cout << -1 << endl;
        }
        else {
            cout << op.size() << endl;
            for(int i = 0; i < op.size(); i++) {
                cout << op[i][0]+1 << " " << op[i][1]+1 << " " << op[i][2]+1 << " " << op[i][3]+1 << endl;
            }
        }
    }
}