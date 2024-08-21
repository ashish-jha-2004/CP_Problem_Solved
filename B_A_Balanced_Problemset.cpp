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
// const int N = pow(10, 8);
// vector<bool> prime(pow(10, 4)+1, 1);
// void sieve_of_eratosthenes(vector<bool> &prime, int n=pow(10, 4)+1) {
//     for (int p = 2; p * p <= n; p++) {
//         if (prime[p] == true) {
//             for (int i = p * p; i <= n; i += p)
//                 prime[i] = false;
//         }
//     }
// }

void solve(){
    // code here
    ll x, n;
    cin >> x >> n;
    if (n == 1){
        cout << x << en;
        return;
    }
    // vector<bool> prime(pow(10, 4)+1, 1);
    // sieve_of_eratosthenes(prime);
    // if (prime[x]){
    //     cout << 1 << en;
    //     return;
    // }
    ll temp = x/n;
    ll ans = 1;
    for (ll i{1}; i*i<=x; i++){
        if(x%i == 0){
            ll j = x/i;
            if (j >= n){
                ans = max(ans, i);
            }
            if(i >= n){
                ans = max(j, ans);
            }
        }
    }
    cout << ans << en;
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