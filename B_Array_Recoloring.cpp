#include <bits/stdc++.h>

void solve() {
    int n, k;
    std::cin >> n >> k;
    std::vector<long long> v(n);

    for (int i = 0; i < n; i++) {
        std::cin >> v[i];
    }

    if (k == 1) {
        long long maxi = v.front() + v.back();
        for (int i = 1; i < n - 1; i++) {
            maxi = std::max(maxi, v[i] + std::max(v.front(), v.back()));
        }
        std::cout << maxi << std::endl;
        return;
    }
    std::sort(v.rbegin(), v.rend());
    long long sum = 0;
    for (int i = 0; i < k; i++) {
        sum += v[i];
        if (i == k - 1) sum += v[i + 1];
    }
    std::cout << sum << std::endl;
}

int main() {
    int t;
    std::cin >> t;
    while (t--) solve();
}