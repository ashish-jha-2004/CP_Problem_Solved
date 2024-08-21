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
    vector<ll> vec(n);
    fl(i, n) cin >> vec[i];
    ll maxi = -1;
    ll mini = INT_MAX;
    fl(i, n){
        mini = min(vec[i], mini);
        maxi = max(vec[i], maxi);
    }
    cout << maxi - mini << endl;
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