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

bool is_b(vector<string> &v, char c, int i){
    fl(j, v[i].size()){
        if (v[i][j] == c){
            return true;
        }
    }
    return false;
}

bool is_h(vector<string> &v, char c, int i){
    fl(j, v.size()){
        if (v[j][i] == c){
            return true;
        }
    }
    return false;
}

void solve(){
    // code here
    int n, m;
    cin >> n >> m;
    vector<string> v(n);
    fl (i, n) cin >> v[i];
    if (v[0][0] == v[n-1][m-1] or v[0][m-1] == v[n-1][0]){
        yes
        return;
    }
    else {
        if (v[0][0] == v[0][m-1] and v[0][0] == 'W'){
            if (is_b(v, 'W', n-1)){
                yes
                return;
            }
        }
        if (v[n-1][0] == v[n-1][m-1] and v[n-1][0] == 'W'){
            if (is_b(v, 'W', 0)){
                yes
                return;
            }
        }
        if (v[0][0] == v[0][m-1] and v[0][0] == 'B'){
            if (is_b(v, 'B', n-1)){
                yes
                return;
            }
        }
        if (v[n-1][0] == v[n-1][m-1] and v[n-1][0] == 'B'){
            if (is_b(v, 'B', 0)){
                yes
                return;
            }
        }
        if (v[n-1][0] == v[0][0] and v[0][0] == 'W'){
            if (is_h(v, 'W', m-1)){
                yes
                return;
            }
        }
        if (v[n-1][m-1] == v[0][m-1] and v[0][m-1] == 'W'){
            if (is_h(v, 'W', 0)){
                yes
                return;
            }
        }
        if (v[n-1][0] == v[0][0] and v[0][0] == 'B'){
            if (is_h(v, 'B', m-1)){
                yes
                return;
            }
        }
        if (v[n-1][m-1] == v[0][m-1] and v[0][m-1] == 'B'){
            if (is_h(v, 'B', 0)){
                yes
                return;
            }
        }
    }
    no
    return;
    
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