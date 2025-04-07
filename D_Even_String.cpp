#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MAXN = 500000;            
const ll MOD  = 998244353;

ll modpow(ll x, ll e = MOD-2) {
    ll r = 1;
    while (e) {
        if (e & 1) r = r * x % MOD;
        x = x * x % MOD;
        e >>= 1;
    }
    return r;
}

ll fact[MAXN+1], invfact[MAXN+1];

void init_factorials() {
    fact[0] = 1;
    for (int i = 1; i <= MAXN; i++)
        fact[i] = fact[i-1] * i % MOD;
    invfact[MAXN] = modpow(fact[MAXN]);
    for (int i = MAXN; i > 0; i--)
        invfact[i-1] = invfact[i] * i % MOD;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    init_factorials();

    int T;
    cin >> T;
    while (T--) {
        vector<int> c(26);
        ll sum = 0;
        for (int i = 0; i < 26; i++) {
            cin >> c[i];
            sum += c[i];
        }

        int O = (sum + 1) / 2;
        int E = sum / 2;

        vector<ll> dp(O+1, 0);
        dp[0] = 1;
        for (int i = 0; i < 26; i++) {
            int w = c[i];
            if (w == 0) continue;
            for (int j = O; j >= w; j--) {
                dp[j] = (dp[j] + dp[j - w]) % MOD;
            }
        }

        ll waysToChooseParity = dp[O]; 
        if (waysToChooseParity == 0) {
            cout << 0 << "\n";
            continue;
        }

        ll invDenom = 1;
        for (int i = 0; i < 26; i++) {
            invDenom = invDenom * invfact[c[i]] % MOD;
        }

        ll ans = waysToChooseParity;
        ans = ans * fact[O] % MOD;
        ans = ans * fact[E] % MOD;
        ans = ans * invDenom % MOD;

        cout << ans << "\n";
    }

    return 0;
}
