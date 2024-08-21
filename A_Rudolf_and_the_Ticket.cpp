#include<iostream>
#include<vector>
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
    int n, m, k;
    cin >> n >> m >> k;
    vector<ll> b(n, 0), c(m, 0);
    fl (i, n) cin >> b[i];
    fl(i, m) cin >> c[i];
    int ans = 0;
    fl (i, n){
        fl (j, m){
            if (b[i]+c[j] <= k) ans++;
        }
    }
    cout << ans << endl;
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