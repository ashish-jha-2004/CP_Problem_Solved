#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    
    while (t--) {
        int n, m, k;
        cin >> n >> m >> k;
        
        vector<vector<int>> heights(n, vector<int>(m));
        vector<vector<char>> types(n, vector<char>(m));
        
        // Reading the heights
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                cin >> heights[i][j];
            }
        }
        
        // Reading the types
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                cin >> types[i][j];
            }
        }
        
        long long snowy_sum = 0, non_snowy_sum = 0;
        
        // Calculating the sums
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (types[i][j] == '0') {
                    snowy_sum += heights[i][j];
                } else {
                    non_snowy_sum += heights[i][j];
                }
            }
        }
        
        // Checking if the sums are equal
        if (snowy_sum == non_snowy_sum) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
    
    return 0;
}
