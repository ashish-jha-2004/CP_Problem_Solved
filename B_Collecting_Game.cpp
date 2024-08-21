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
#define d_v(v, n) vl v(n); fl(i, n) cin >> v[i];
#define en "\n"
#define F first
#define S second
#define PB(a) push_back(a)
#define PPB pop_back()
#define MP make_pair
#define B begin()
#define E end()

// ll next_false(vector<bool> &b, int s){
//     fn(i, s, b.size()){
//         if (b[i] == 0) return i;
//     }
//     return b.size()-1;
// }

void solve(){
    // code here
    d_n(n);
    d_v(v, n);
    vl v1 = v;
    sortall(v1);
    map<ll, ll> mp;
    vl pref(n, 0);
    vector<bool> b(n, 0);
    ll sum = 0;
    fl(i, n){
        sum += v1[i];
        pref[i] = sum;
        if (i == n-1){
            b[i] = false;
            break;
        }
        if (pref[i] >= v1[i+1]){
            b[i] = true;
        }
    }
    // for (auto i: b){
    //     cerr << i << " ";
    // }
    // cerr << en;
    int su = 0;
    vl data(n);
    for (int i{n-1}; i>=0; i--){
        if (b[i] == false){
            su = 0;
            data[i] = su;
        }
        else {
            su += 1;
            data[i] = su;
        }
    }
    fl(i, n){
        if (mp.find(v1[i]) == mp.end()){
            mp[v1[i]] = data[i]+i;
        }
    }
    fl(i, n){
        cout << mp[v[i]] << " ";
    }
    cout << en;
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