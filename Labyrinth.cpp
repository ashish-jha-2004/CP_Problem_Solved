#include <bits/stdc++.h>
using namespace std;

int n, m;
int sti, stj, eni, enj;
bool vis[1000][1000];
bool g[1000][1000];

// Direction vectors and corresponding movement labels
vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
vector<char> directionLabels = {'U', 'D', 'L', 'R'};

string dfs(int i, int j) {
    // If we reached the endpoint, return an empty string to begin path construction
    if (i == eni && j == enj) return "";
    
    vis[i][j] = true; // Mark the cell as visited
    string path;
    
    // Explore all 4 directions (Up, Down, Left, Right)
    for (int d = 0; d < 4; d++) {
        int ni = i + directions[d].first;
        int nj = j + directions[d].second;
        
        // Check within bounds and if the cell is walkable and unvisited
        if (ni >= 0 && ni < n && nj >= 0 && nj < m && g[ni][nj] && !vis[ni][nj]) {
            path = dfs(ni, nj);
            if (!path.empty() || (ni == eni && nj == enj)) {
                return directionLabels[d] + path; // Add direction and propagate path upwards
            }
        }
    }
    return ""; // Return empty if no path is found
}

void solve() {
    // Input grid dimensions
    cin >> n >> m;

    // Input grid and mark walkable cells
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            char cell;
            cin >> cell;
            if (cell == 'A') {
                sti = i; stj = j; // Start point
            }
            if (cell == 'B') {
                eni = i; enj = j; // End point
            }
            g[i][j] = (cell != '#'); // Mark as walkable if not wall
        }
    }

    // Start DFS from the starting point
    string path = dfs(sti, stj);

    // Output results
    if (path.empty()) {
        cout << "NO\n"; // No path found
    } else {
        cout << "YES\n" << path.size() << '\n' << path << '\n'; // Path found with details
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
