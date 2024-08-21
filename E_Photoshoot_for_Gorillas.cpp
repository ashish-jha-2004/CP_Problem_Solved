#include <bits/stdc++.h>

using namespace std;

const int M = 2e5 + 5;
long long a[M];

void solve() {
	int n, m, k; cin >> n >> m >> k;
	vector<int> cnt;
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= m; j++) {
			int x = max(i - k + 1, 1);
			int y = max(j - k + 1, 1);
			int u = min(i, n - k + 1);
			int v = min(j, m - k + 1);
			cnt.push_back((u - x + 1) * (v - y + 1));
		}
	}
	sort(cnt.begin(), cnt.end(), greater<int>());
	int w; cin >> w;
	long long ans = 0;
	for(int i = 0; i < w; i++) cin >> a[i];
	sort(a, a + w, greater<long long>());
	for(int i = 0; i < w; i++) ans += a[i] * cnt[i];
	cout << ans << endl;
}

int main() {
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
