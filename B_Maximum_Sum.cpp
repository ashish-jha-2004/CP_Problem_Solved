#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

const int MOD = 1000000007;
#define int long long

void solve() {
    int n, k;
    cin >> n >> k;
    int summ = 0;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        summ += a[i];
    }
    int maxi = 0;
    int s0 = 0;
    for (int i : a) {
        s0 += i;
        if (s0 < 0) {
            s0 = 0;
        } else {
            maxi = max(s0, maxi);
        }
    }

    if (maxi > 0) {
        summ += (((long long)pow(2, k) - 1) * maxi);
    }

    long long ans = (long long)summ % MOD;
    cout << ans << endl;
}

signed main() {
    int t;
    cin >> t;
    cin.ignore();
    for (int i = 0; i < t; i++) {
        solve();
    }
    return 0;
}
