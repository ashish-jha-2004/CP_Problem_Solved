#include <bits/stdc++.h>    
using namespace std;

const int MAXN = 1e5 + 10;

class Union_set {
private:
    int parent[MAXN];
    int size[MAXN];
public:
    void make_set(int x) {
        parent[x] = x;
        size[x] = 1;
    }
    int find_set(int v) {
        if (parent[v] == v) return v;
        return parent[v] = find_set(parent[v]);
    }
    void Union(int a, int b) {
        a = find_set(a);
        b = find_set(b);
        if (size[a] < size[b]) swap(a, b);
        parent[b] = a;
        size[a] += size[b];
    }
};
    
int main() {
    int n, k;
    cin >> n >> k;
    Union_set s;
    for (int i{1}; i<=n; ++i) {
        s.make_set(i);
    }
    while (k--) {
        int u, v;
        cin >> u >> v;
        s.Union(u, v);
    }
    int cnt = 0;
    for (int i{1}; i<=n; ++i) {
        if (i == s.find_set(i)) cnt++;
    }
    cout << cnt << endl;
}