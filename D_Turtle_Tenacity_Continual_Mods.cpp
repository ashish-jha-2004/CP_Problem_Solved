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
#define PB push_back()
#define PPB pop_back() 
#define MP make_pair
#define B begin()
#define E end()

void solve(){
    // code here
    int n;
    cin >> n;
    vl v(n, 0);
    // unordered_map<ll, ll> m;
    set<ll> s;
    fl(i, n) {
        cin >> v[i];
        // m[v[i]] = 0;
        s.insert(v[i]);
    }
    // bool flag = false;
    // fl(i, n){
    //     if(v[i] == 1){
    //         flag = true;
    //     }
    //     m[v[i]]++;
    // }
    sort(v.B, v.E);
    if (v[0] == 0){
        no
        return;
    }
    // if (flag and m[1] >= 2){
    //     no
    //     return; 
    // }
    for (auto it = s.rbegin(); it != s.rend(); it++){
        ll temp = *it;
        bool flag = true;
        int fd = 0;
        for (ll i{0}; i<n; i++){
            if(*it == v[i] and fd == 0){
                fd++;
                continue;
            }
            temp = temp % v[i];
            if(temp == 0){
                flag = false;
                break;
            }
        }
        if (flag){
            yes
            return;
        }
    }
    no
    return;
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