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
#define fn(i, j, k) for(int i{j}; i<k; i++)
#define no cout << "NO\n";
#define yes cout << "YES\n";
#define sortall(v) sort(v.begin(), v.end())
#define d_n(n) ll n; cin >> n
#define d_v(v, n) vl v(n); fl(i, n) cin >> v[i]
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
    ll n, m, k;
    cin >> n >> m >> k;
    d_v(v, n);
    sortall(v);
    ll inf = 0;
    ll sum = 0;
    // for (auto i : v){
    //     cerr << i << " ";
    // }
    // cerr << en;
    ll inc = 0;
    fl (i, n){
        if (k >= m){
            k -= m;
            
            inf += inc*m;
            inc += m;
            sum += m*v[i];
        }
        else {
            // cerr << k << en;
            
            inf += inc*k;
            sum += k*v[i];
            k = 0;
        }
        if (k == 0){
            break;
        }
    }
    std::cout << sum + inf << en;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    d_n(t);
    while (t--){
        solve();
    }
    return 0;
}