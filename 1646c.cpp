#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;
typedef long long ll;
 
ll count1(ll a) {
    ll c = 0;
    while(a) {
        c += a & 1;
        a >>= 1;
    }
    return c;
}
 
int main() {
    int T;
    cin >> T;
    vector<ll> fact;
    fact.assign(17, 0);
    fact[0] = 6;
    for(int i = 1; i < 17; i++) {
        fact[i] = fact[i-1]*(i+3);
    }
    while(T--) {
        ll n;
        cin >> n;
        ll opt = 1000000;
        for(ll f = 0; f < pow(2, fact.size()); f++) {
            ll sum = 0;
            ll x = f;
            int o = 0;
            while(x && o < fact.size()) {
                if(x & 1) {
                    sum += fact[o];
                }
                x >>= 1;
                o++;
            }
            if(n >= sum) opt = min(opt, count1(f) + count1(n-sum));
        }
        cout << opt << endl;
    }
    return 0;
}