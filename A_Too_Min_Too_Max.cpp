#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fl(i, j) for(int i{0}; i<j; i++)
#define no cout << "NO\n";
#define yes cout << "YES\n";

void solve(){
    // code here
    int n;
    cin >> n;
    vector<ll> v(n);
    fl(i, n) cin >> v[i];
    sort(v.begin(), v.end());
    cout << 2*abs(v[n-1] - v[0]) + 2*abs(v[n-2] - v[1]) << endl;
}

int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--){
        solve();
    }
    return 0;
}