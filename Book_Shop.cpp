#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int n, x;
    cin >> n >> x;
    vector<int> prices(n), values(n);
    for (int i = 0; i < n; i++) {
        cin >> prices[i] ;
    }
    for (int i = 0; i < n; i++) {
        cin >> values[i] ;
    }

    vector<ll> dp(x + 1, 0);

    for (int i = 0; i < n; i++) {
        for (int j = x; j >= prices[i]; j--) {
            dp[j] = max(dp[j], dp[j - prices[i]] + values[i]);
        }
    }

    cout << dp[x] << "\n";
    return 0;
}
