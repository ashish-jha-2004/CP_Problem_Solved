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

bool check(vector<vector<ll>> &v, vector<ll> &maxi){
    ll n = v.size();
    fl(i, n){
        fl(j, n){
            if (i == j){
                continue;
            }
            else {
                if (v[i][j] != (maxi[i]|maxi[j])){
                    return false;
                }
            }
        }
    }
    return true;
}

void solve(){
    // code here
    int n;
    ll large = 0;
    cin >> n;
    vector<vector<ll>> v(n, vector<ll> (n));
    vector<ll> maxi;
    
    fl(i, n){
        fl(j, n){
            cin >> v[i][j];
        }
    }
    if (n == 1){
        yes
        cout << 7 << en;
        return;
    }
    fl(i, n){
        ll temp = v[i][0];
        if (i == 0){
            temp = v[i][1];
        }
        fn(j, 1, n){
            if (i != j)
                temp = temp & v[i][j];
        }
        // cout << temp << " ";
        maxi.PB(temp);
    }
    if (!check(v, maxi)){
        no
    }
    else {
        yes
        for (auto &h : maxi){
            cout << h << " ";
        }
        cout << en;
    }
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