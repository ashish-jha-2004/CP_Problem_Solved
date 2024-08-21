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
    int n;
    cin >> n;
    vector<ll> a(n, 0), b(n, 0);
    fl(i, n) cin >> a[i];
    fl(i, n) cin >> b[i];
    ll min_a = a[0], min_b = b[0];
    fl(i, n){
        min_a = min(a[i], min_a);
        min_b = min(b[i], min_b);
    }
    ll sum_a = 0, sum_b = 0;
    fl(i, n) {
        sum_a = sum_a + (min_b + a[i]);
        sum_b = sum_b + (min_a + b[i]);
    }
    cout << min(sum_a, sum_b) << endl;

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