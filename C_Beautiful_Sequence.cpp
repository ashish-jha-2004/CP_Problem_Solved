#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

typedef long long ll;
typedef vector<ll> vl;

ll modpow(ll a, ll b, ll mod = 998244353) {
    ll res = 1;
    a %= mod;
    while(b > 0) {
        if(b & 1)
            res = (res * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return res;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++){
            cin >> a[i];
        }
        vector<int> P(n+1, 0);
        for (int i = 0; i < n; i++){
            P[i+1] = P[i] + (a[i] == 2);
        }
        int maxPow = n + 1;
        vector<ll> pow2(maxPow+1), inv2(maxPow+1);
        for (int i = 0; i <= maxPow; i++){
            pow2[i] = modpow(2, i, 998244353);
            inv2[i] = modpow(pow2[i], 998244353-2, 998244353);
        }
        ll ans = 0;
        ll S = 0;
        ll C = 0;
        for (int i = 0; i < n; i++){
            if(a[i] == 1){
                S = (S + inv2[P[i+1]]) % 998244353;
                C++;
            }
            else if(a[i] == 3){
                ll contrib = ((pow2[P[i]] * S) % 998244353 - C) % 998244353;
                if (contrib < 0) contrib += 998244353;
                ans = (ans + contrib) % 998244353;
            }
        }
        cout << ans % 998244353 << "\n";
    }
    return 0;
}
