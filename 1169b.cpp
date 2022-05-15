#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
 
void print_vector(vector<vector<int>> &graph, int n) {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < graph[i].size(); j++) {
            cout << graph[i][j]+1 << " ";
        }
        cout << endl;
    }
}
 
int binary_search(vector<vector<int>> &graph, int n, int c, int x) {
    int l = 0;
    int r = graph[c].size()-1;
    while(l <= r) {
        int m = (l+r)/2;
        if(graph[c][m] == x) return m;
        else if(graph[c][m] < x) l = m+1;
        else r = m-1;
    }
    return -1;
}
 
vector<int> find_vectors(vector<vector<int>> &graph, int n, int m) {
    vector<int> result;
    for(int i = 0; i < n; i++) {
        if(graph[i].size()*2 >= m) {
            result.push_back(i);
        }
    }
    return result;
}
 
vector<int> find_vectors2(vector<vector<int>> &graph, int n, int m, int c) {
    vector<int> result;
    for(int i = 0; i < n; i++) {
        if(i == c) continue;
        if(graph[i].size() + graph[c].size() < m) continue;
        int x = 0;
        int y = 0;
        int s = 0;
        if(binary_search(graph, n, c, i) != -1) s++;
        if(graph[c].size() + graph[i].size() - s >= m) result.push_back(i);
    }
    return result;
}
 
int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> graph;
    for(int i = 0; i < n; i++) {
        vector<int> empty;
        graph.push_back(empty);
    }
    set<pair<int, int>> s;
    int m2 = m;
    for(int i = 0; i < m2; i++) {
        int x, y;
        cin >> x >> y;
        x--; y--;
        if(s.find({min(x, y), max(x, y)}) == s.end()) {
            graph[x].push_back(y);
            graph[y].push_back(x);
            s.insert({min(x, y), max(x, y)});
        }
        else {
            m--;
        }
    }
    for(int i = 0; i < n; i++) {
        sort(graph[i].begin(), graph[i].end());
    }
    vector<int> candidates = find_vectors(graph, n, m);
    bool res = false;
    for(int i = 0; i < candidates.size(); i++) {
        vector<int> c2 = find_vectors2(graph, n, m, candidates[i]);
        for(int j = 0; j < c2.size(); j++) {
            res = true;
            break;
        }
        if(res) {
            break;
        }
    }
    if(res) cout << "YES" << endl;
    else cout << "NO" << endl;
}