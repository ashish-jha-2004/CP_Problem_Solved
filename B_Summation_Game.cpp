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

ll sum(vector<ll> v, int i, int x){
    ll s = 0;
    // if(i < 0) {
    //     return s;
    // }
    fl(j, i){
        if(j >= i-x){
            s += -1*v[j];
        }
        else {
            s += v[j];
        }
    }
    return s;
}

void solve(){
    // code here
    int n, k, x;
    cin >> n >> k >> x;
    vector<ll> v(n, 0);
    fl(i, n) cin >> v[i];
    sort(v.begin(), v.end());
    ll sum_ini = sum(v, n, x);
    ll maxi = sum_ini;
    for (int i{1}; i<=k; i++){
        ll sum_now = sum(v, n-i, x);
        maxi = max(maxi, sum_now);
    }
    cout << maxi << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(nullptr);
    int t;
    cin >> t;
    while (t--){
        solve();
    }
    return 0;
}