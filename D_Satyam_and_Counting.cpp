#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
using namespace std;

int main() {
    int T;
    cin >> T;
    
    while (T--) {
        int n;
        cin >> n;
        
        vector<pair<int, int>> nums(n);
        unordered_map<int, int> b;
        set<pair<int, int>> check;
        for (int i = 0; i < n; ++i) {
            int x, y;
            cin >> x >> y;
            nums[i] = {x, y};
            b[x]++;
            check.insert({x, y});
        }

        long long ans = 0;
        for (const auto& p : b) {
            if (p.second == 2) {
                ans += n - 2;
            }
        }
        for (const auto& p : check) {
            int x = p.first;
            int y = p.second;
            if (check.count({x - 1, y ^ 1}) && check.count({x + 1, y ^ 1})) {
                ans++;
            }
        }

        cout << ans << endl;
    }
    
    return 0;
}

