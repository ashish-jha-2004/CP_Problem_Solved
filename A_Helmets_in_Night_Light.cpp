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
    d_n(n);
    d_n(p);
    vector<ll> v1(n, 0), v2(n, 0);
    fl(i, n){
        cin >> v1[i];
    }
    fl(i, n){
        cin >> v2[i];
    }
    multimap<ll, ll> mp;
    fl(i, n){
        mp.insert({v2[i], v1[i]});
    }
    sortall(v2);
    ll sum = 0;
    ll i = n-1;
    for (auto it: mp){
        if (i <= 0){
            break;
        }
        if (it.first < p){
            i -= it.second;
            sum += it.first * it.second;
            if (i < 0){
                sum -= -1*i*it.first;
            }
        }
        else {
            sum += (i)*p;
            break;
        }
    }
    cout << sum+p << en;

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    d_n(t);
    while (t--){
        solve();
        // break;
    }
    return 0;
}