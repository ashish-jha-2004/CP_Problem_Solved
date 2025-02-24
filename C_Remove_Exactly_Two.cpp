#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        // Vertices are numbered 1..n.
        // deg[v] will hold the degree of vertex v.
        vector<int> deg(n + 1, 0);
        // For quick adjacency checking, we store the neighbors of each vertex.
        vector<unordered_set<int>> neighbors(n + 1);

        // Read the n - 1 edges.
        for (int i = 1; i < n; i++){
            int u, v;
            cin >> u >> v;
            deg[u]++;
            deg[v]++;
            neighbors[u].insert(v);
            neighbors[v].insert(u);
        }

        // Special case: if n == 2, the only edge connects the two vertices.
        // Removing both vertices leaves 0 connected components.
        if(n == 2){
            cout << 0 << "\n";
            continue;
        }

        // Find the maximum degree (dmax) and collect all vertices achieving dmax.
        int dmax = 0;
        vector<int> vertices_max;
        for (int v = 1; v <= n; v++){
            if(deg[v] > dmax){
                dmax = deg[v];
                vertices_max.clear();
                vertices_max.push_back(v);
            } else if(deg[v] == dmax){
                vertices_max.push_back(v);
            }
        }

        int best = 0;
        // Case 1: At least two vertices with maximum degree.
        if (vertices_max.size() >= 2) {
            // If there are three or more vertices with dmax,
            // then by the tree structure (no triangles), at least one pair is non‐adjacent.
            if (vertices_max.size() >= 3) {
                best = 2 * dmax - 1;
            } else {
                // Exactly two vertices with degree dmax.
                int u = vertices_max[0], v = vertices_max[1];
                // Check whether u and v are adjacent.
                if (neighbors[u].find(v) != neighbors[u].end())
                    best = 2 * dmax - 2; // They are adjacent.
                else
                    best = 2 * dmax - 1; // They are not adjacent.
            }
        } else {
            // Case 2: There is a unique vertex with maximum degree.
            int v_max = vertices_max[0];
            int d2 = 0; // Maximum degree among vertices other than v_max.
            for (int v = 1; v <= n; v++){
                if(v == v_max)
                    continue;
                if(deg[v] > d2)
                    d2 = deg[v];
            }

            // Check if there exists a vertex of degree d2 that is not adjacent to v_max.
            bool non_adjacent_found = false;
            for (int v = 1; v <= n; v++){
                if(v == v_max)
                    continue;
                if(deg[v] == d2 && neighbors[v_max].find(v) == neighbors[v_max].end()){
                    non_adjacent_found = true;
                    break;
                }
            }
            if(non_adjacent_found)
                best = dmax + d2 - 1;
            else
                best = dmax + d2 - 2;
        }

        cout << best << "\n";
    }
    return 0;
}
