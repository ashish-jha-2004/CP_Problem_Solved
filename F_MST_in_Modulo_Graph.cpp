#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
 
struct DSU {
    vector<int> parent;
    DSU(int n) : parent(n) {
        for (int i = 0; i < n; i++)
            parent[i] = i;
    }
    int find(int a) {
        return parent[a] == a ? a : parent[a] = find(parent[a]);
    }
    // Returns true if a merge happened
    bool unite(int a, int b) {
        a = find(a);
        b = find(b);
        if(a == b) return false;
        parent[b] = a;
        return true;
    }
};
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> p(n);
        for (int i = 0; i < n; i++){
            cin >> p[i];
        }
        if(n == 1){
            cout << 0 << "\n";
            continue;
        }
        // Create a vector of pairs: (weight, original index)
        vector<pair<int,int>> sorted;
        sorted.reserve(n);
        for (int i = 0; i < n; i++){
            sorted.push_back({p[i], i});
        }
        sort(sorted.begin(), sorted.end());
        
        DSU dsu(n);
        long long ans = 0;
        int max_p = sorted.back().first;
        
        // Process vertices in increasing order.
        // For each vertex with weight 'a', we try to union it with vertices
        // whose weights lie in the interval [mult*a, mult*a + a).
        // If a divides that vertex’s weight, the edge cost is 0.
        for (int i = 0; i < n; i++){
            int a = sorted[i].first;
            for (int mult = 2; mult * a <= max_p; mult++){
                int L = mult * a;
                int R = L + a;
                auto it = lower_bound(sorted.begin(), sorted.end(), make_pair(L, -1));
                while(it != sorted.end() && it->first < R){
                    // if not divisible, break out: no later candidate in this block will be beneficial
                    if(it->first % a != 0)
                        break;
                    // The edge weight is it->first % a (which is 0 here)
                    if(dsu.unite(sorted[i].second, it->second))
                        ans += (it->first % a);
                    ++it;
                }
            }
        }
        
        // Connect any remaining components using the global minimum vertex.
        // For a vertex with weight w and the global minimum minVal,
        // the cost is w mod minVal (which is 0 if minVal divides w).
        int minVal = sorted[0].first;
        int minIndex = sorted[0].second;
        for (int i = 1; i < n; i++){
            if(dsu.find(minIndex) != dsu.find(sorted[i].second)){
                ans += sorted[i].first % minVal;
                dsu.unite(minIndex, sorted[i].second);
            }
        }
        
        cout << ans << "\n";
    }
    return 0;
}
