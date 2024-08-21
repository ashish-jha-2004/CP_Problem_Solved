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

void solve(vl &v){
    // code here
    d_n(n);
    d_n(k);
    ll temp = 0;
    if (n == 1){
        cout << k << en;
        return;
    }
    fl(i, 33){
        if (v[i] > k){
            temp = v[i-1];
            break;
        }
    }
    // cerr << temp << en;
    fl(i, n-2){
        cout << 0 << " ";
    }
    cout << temp << " " << k-temp << en;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    d_n(t);
    vl v;
    ll a = 1;
    fn(i, 1, 34){
        v.push_back(a);
        a = a*2 + 1;
    }
    while (t--){
        solve(v);
    }
    return 0;
}