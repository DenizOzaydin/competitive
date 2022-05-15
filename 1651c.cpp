#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
 
ll min(ll a, ll b) {
    return a < b ? a : b;
}
 
ll solve(vector<ll> &a, vector<ll> &b, int n, ll a0, ll a1, ll b0, ll b1) {
    ll a0b0 = abs(a[0]-b[0]);
    ll a0b1 = abs(a[0]-b[n-1]);
    ll a1b0 = abs(a[n-1]-b[0]);
    ll a1b1 = abs(a[n-1]-b[n-1]);
    //3 3 10 15
    //19 24 19 24
    vector<ll> results;
    results.push_back(a0+a1+b0+b1);
    results.push_back(a0b0+a1b1);
    results.push_back(a0b1+a1b0);
    results.push_back(a0b0+min(a1, a1b0)+min(b1, a0b1)); 
    results.push_back(a0b1+a1+b0);
    results.push_back(a0b1+min(a1, a1b1)+min(b0, a0b0)); 
    results.push_back(a1b0+a0+b1);
    results.push_back(a1b0+min(a0, a0b0)+min(b1, a1b1)); 
    results.push_back(a1b1+a0+b0);
    results.push_back(a1b1+min(a0, a0b0)+min(b0, a1b0)); 
    ll m = 200000000000;
    for(int i = 0; i < results.size(); i++) {
        m = min(m, results[i]);
    }
    return m;
}
 
int main() {
    int T;
    cin >> T;
    while(T--) {
        int n;
        cin >> n;
        vector<ll> a;
        vector<ll> b;
        for(int i = 0; i < n; i++) {
            ll x;
            cin >> x;
            a.push_back(x);
        }
        for(int i = 0; i < n; i++) {
            ll x;
            cin >> x;
            b.push_back(x);
        }
        ll sum = 0;
        ll m = 2000000000;
        for(int i = 1; i < n-1; i++) {
            m = min(m, abs(a[0]-b[i]));
        }
        ll a1 = m;
        sum += m;
        m = 2000000000;
        for(int i = 1; i < n-1; i++) {
            m = min(m, abs(a[n-1]-b[i]));
        }
        sum += m;
        ll a2 = m;
        m = 2000000000;
        for(int i = 1; i < n-1; i++) {
            m = min(m, abs(a[i]-b[0]));
        }
        sum += m;
        ll b1 = m;
        m = 2000000000;
        for(int i = 1; i < n-1; i++) {
            m = min(m, abs(a[i]-b[n-1]));
        }
        sum += m;
        ll b2 = m;
        cout << solve(a, b, n, a1, a2, b1, b2) << endl;
    }
}