#include<bits/stdc++.h>
using namespace std;
/*
************************************************************************************************************************************************
    Author :- Ashish Jha
    Yug :- Kaliyug
************************************************************************************************************************************************
    ॐ त्र्यम्बकं यजामहे
    सुगन्धिं पुष्टिवर्धनम् ।
    उर्वारुकमिव बन्धनान्
    मृत्योर्मुक्षीय मामृतात् ॥
************************************************************************************************************************************************
*/

typedef long long ll;
#define fl(i, j) for(ll i{0}; i<j; i++)
#define finl(i, j, k) for(ll i{j}; i<k; i++)
#define no cout << "NO\n";
#define yes cout << "YES\n";

void solve(){
    // code here
    ll a, b;
    cin >> a >> b;
    ll xk, yk;
    cin >> xk >> yk;
    ll xq, yq;
    cin >> xq >> yq;

    set<pair<ll, ll>> s1,s2;
    for (ll _ = 0; _ < 2; _++) {
        swap(a, b);
        for (ll d1 = -1; d1 <= 1; d1 += 2) {
            for (ll d2 = -1; d2 <= 1; d2 += 2) {
                s1.insert({xk + a * d1, yk + b * d2});
            }
        }
    }
    for (ll _ = 0; _ < 2; _++) {
        swap(a, b);
        for (ll d1 = -1; d1 <= 1; d1 += 2) {
            for (ll d2 = -1; d2 <= 1; d2 += 2) {
                s2.insert({xq + a * d1, yq + b * d2});
            }
        }
    }

    ll ans = 0;
    for (auto el:s2) {
        if (s1.find(el) != s1.end())ans++;
    }

    cout << ans << '\n';


}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin >> t;
    while (t--){
        solve();
    }
    return 0;
}