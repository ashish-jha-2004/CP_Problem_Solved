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
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<char> vc;
typedef pair<int, int> pii;
typedef pair<int, char> pic;
#define fl(i, j) for(int i{0}; i<j; i++)
#define finl(i, j, k) for(int i{j}; i<k; i++)
#define no cout << "NO\n";
#define yes cout << "YES\n";
#define en "\n"
#define F first
#define S second
#define PB(a) push_back(a)
#define PPB pop_back() 
#define MP make_pair
#define B begin()
#define E end()

void solve(){
    // code here
    int n;
    cin >> n;
    vector<ll> v(n), dp(n+1, 0);
    fl(i, n){
        cin >> v[i];
    }
    dp[n-1] = n;
    for (int i{n-2}; i>=0; i--){
        if (v[i] == v[i+1]){
            dp[i] = dp[i+1];
        }
        else {
            dp[i] = i+1;
        }
    }
    int q;
    cin >> q;
    while (q--){
        int l, r;
        cin >> l >> r;
        if (l == r){
            cout << "-1 -1\n";
            continue;
        }
        l--; r--;
        if (dp[l] > r){
            cout << "-1 -1\n";
        }
        else if (dp[l] <= r){
            cout << l+1 << " " << dp[l]+1 << en;
        }
    }
    cout << en;

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