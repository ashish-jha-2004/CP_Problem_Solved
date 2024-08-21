#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define fl(i, j) for(int i{0}; i<j; i++)

ll mere_liye(ll a, ll x){
    return (x-(a%x))%x;
}

void solve(){
    ll n, x, y;
    cin >> n >> x >> y;
    vector<ll> v(n);
    fl(i, n) cin >> v[i];
    map<ll, map<ll, ll>> m;
    fl(i, n){
        m[v[i]%x][v[i]%y]++;
    }
    ll answer = 0;
    fl(i, n){
        answer += (m[mere_liye(v[i], x)][v[i]%y] - (v[i]%x == mere_liye(v[i], x)));
    }
    cout << (answer/2) << endl; 
}


int main(){
    int y;
    cin >> y;
    while (y--){
        solve();
    }
    return 0;
}