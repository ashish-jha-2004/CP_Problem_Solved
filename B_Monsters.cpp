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
#define sortall(v) sort(v.rbegin(), v.rend())
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
    d_n(k);
    vl v(n, 0);
    map<ll, vector<ll>, greater<int>> mp;
    fl(i, n){
        cin >> v[i];
        ll y = v[i]%k;
        if (v[i]%k == 0){
            y = k;
            if (mp.find(y) != mp.end()){
                mp[y].push_back(i+1);
            }
            if (mp.find(y) == mp.end()) {
                vector<ll> x;
                x.push_back(i+1);
                if (y == 0){
                    mp.insert({k, x});
                }
                else {
                    mp.insert({y, x});
                }
            }
        }
        else {
            if (mp.find(y) != mp.end()){
                mp[y].push_back(i+1);
            }
            if (mp.find(y) == mp.end()) {
                vector<ll> x;
                x.push_back(i+1);
                if (y == 0){
                    mp.insert({k, x});
                }
                else {
                    mp.insert({y, x});
                }
            }
        }
    }

    for (auto i: mp){
        fl (j, i.S.size()){
            cout << i.S[j] << " ";
        }
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