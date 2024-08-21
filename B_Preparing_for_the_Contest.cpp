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
#define fnl(i, j, k) for(int i{j}; i<k; i++)
#define no cout << "NO\n";
#define yes cout << "YES\n";

void solve(){
    // code here
    ll n, k;
    cin >> n >> k;
    if (k == 0){
        fl(i, n) cout << n-i << " ";
    }
    else if (k == n-1){
        fl(i, n) cout << i+1 << " ";
    }
    else {
        for (ll i{n-k}; i>=1; i--){
            cout << i << " ";
        }
        for (ll i{n-k+1}; i<=n; i++){
            cout << i << " ";
        }
    }
    cout << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--){
        solve();
    }
    return 0;
}