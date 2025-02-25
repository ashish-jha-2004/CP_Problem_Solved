#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
 
#define fl(i, j) for (int i = 0; i < j; i++)
#define no cout << "No\n"
#define yes cout << "Yes\n"
 
template<typename... T>
void read(T&... args) { (cin >> ... >> args); }
 
void solve(){
    ll n, m;
    read(n, m);
    
    map<ll, ll> freq;
    ll sum_a = 0;
    for (int i = 0; i < n; i++){
        ll x;
        read(x);
        freq[x]++;
        sum_a += x;
    }
    
    map<ll, ll> mp;
    ll sum_b = 0;
    for (int i = 0; i < m; i++){
        ll x;
        read(x);
        sum_b += x;
        mp[x]++;
    }
    
    if(sum_a != sum_b){
        no;
        return;
    }
    
    while(!mp.empty()){
        auto it = mp.rbegin();
        ll x = it->first, cnt = it->second;
        mp.erase(x);  
        
        if(freq[x] > 0){
            ll matched = min(freq[x], cnt);
            freq[x] -= matched;
            cnt -= matched;
        }
        
        if(cnt == 0) continue;
        
        if(x == 1){
            no;
            return;
        }
        
        ll left = x / 2;
        ll right = x - left;
        mp[left] += cnt;
        mp[right] += cnt;
    }
    
    yes;
}
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    read(t);
    while(t--){
        solve();
    }
    return 0;
}
