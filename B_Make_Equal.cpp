#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define fl(i, j) for(long long int i{0}; i<j; i++)
#define PI 3.14159

void solve(){
    ll n;
    cin >> n;
    vector<ll> v(n);
    for (int i{0}; i<n; i++){
        cin >> v[i];
    }
    ll sum = 0;
    sum = accumulate(v.begin(), v.end(), sum);
    ll lst = sum/n;
    ll ex = 0;
    for (int i{0}; i<n; i++){
        if (v[i] >= lst){
            ex += abs(v[i] - lst);
        }
        else {
            ll r = abs(v[i] - lst);
            if (r > ex){
                cout << "NO\n";
                return;
            }
            else {
                v[i] += r;
                ex -= r;
            }
        }
    }
    cout << "YES\n";
    return;
}

int main(){
    int t;
    cin >> t;

    while (t--){
        solve();
    }
}