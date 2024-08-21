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

ll Mex(vl &v1){
    fl(i, v1.size()){
        if (v1[i] == 0){
            return i;
        }
    }
    return v1.size();
}

void solve(){
    // code here
    int n;
    cin >> n;
    vl v(n, 0), v1(n, 0);
    fl(i, n) {
        cin >> v[i];
        v1[v[i]] = 1;
    }
    ll mex = Mex(v1);
    // cerr << mex << en;
    ll temp = mex;
    int pos = 0;
    unordered_set<ll> s;
    fl(i, n){
        if (v[i] < mex and s.find(v[i]) == s.end()){
            temp--;
            s.insert(v[i]);
        }
        if (temp <= 0){
            pos = i+1;
            break;
        }
    }
    unordered_set<ll> s1;
    ll temp1 = mex;
    int pos1 = -1;
    finl(i, pos, n){
        if (v[i] < mex and s1.find(v[i]) == s1.end()){
            temp1--;
            s1.insert(v[i]);
        }
        if (temp1 <= 0){
            pos1 = i+1;
            break;
        }
    }
    if (pos1 != -1){
        cout << 2 << en;
        cout << 1 << " " << pos << en;
        cout << pos + 1 << " " << n << en;
    }
    else {
        cout << pos1 << en;
    }
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