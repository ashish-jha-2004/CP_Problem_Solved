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
#define fl(i, j) for(int i{0}; i<j; i++)
#define finl(i, j, k) for(int i{j}; i<k; i++)
#define no cout << "NO\n";
#define yes cout << "YES\n";


void solve(){
    // code here
    int n, k, x;
    cin >> n >> k >> x;
    vector<ll> v(n, 0);
    fl(i, n) cin >> v[i];
    sort(v.begin(), v.end());
    ll total_sum = 0;
    vector<ll> pref(n+1, 0);
    fl (i, n) {
        total_sum += v[i];
        pref[i+1] = total_sum;
    }
    if (x == 0) {
        cout << total_sum << endl;
        return;
    }
    ll sum_ini = pref[n-x] - (pref[n] - pref[n-x]);
    ll maxi = sum_ini;
    for (ll i{1}; i<=k; i++){
        if (n-i-x >= 0){
            ll sum_now = pref[n-i-x] - (pref[n-i] - pref[n-i-x]);
            maxi = max(maxi, sum_now);
        }
        else {
            maxi = max(maxi, -1*pref[n-i]);
        }
    }
    cout << maxi << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--){
        solve();
    }
    return 0;
}