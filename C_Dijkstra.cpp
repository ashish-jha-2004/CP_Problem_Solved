#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>

using namespace std;

const int INF = 1e9;
const int MAXN = 1e5 + 5;

vector<pair<int, int>> adj[MAXN];
int dist[MAXN];
int parent[MAXN];
bool visited[MAXN];

void dijkstra(int n) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, 1});
    dist[1] = 0;

    while (!pq.empty()) {
        int u = pq.top().second;
        int d = pq.top().first;
        pq.pop();

        if (d > dist[u]) continue;

        for (auto edge : adj[u]) {
            int v = edge.first;
            int w = edge.second;

            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                parent[v] = u;
                pq.push({dist[v], v});
            }
        }
    }
}

bool dfs(int u, int target) {
    if (u == target) return true;
    visited[u] = true;
    for (auto edge : adj[u]) {
        int v = edge.first;
        if (!visited[v]) {
            if (dfs(v, target)) return true;
        }
    }
    return false;
}

int main() {
    int n, m;
    cin >> n >> m;

    fill(dist, dist + n + 1, INF);
    fill(parent, parent + n + 1, -1);
    fill(visited, visited + n + 1, false);

    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    dijkstra(n);

    if (!dfs(1, n)) {
        cout << -1 << endl;
    } 
    else {
        vector<int> path;
        for (int v = n; v != -1; v = parent[v]) {
            path.push_back(v);
        }

        reverse(path.begin(), path.end());

        for (int v : path) {
            cout << v << " ";
        }
        cout << endl;
    }

    return 0;
}
