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

ll ifp1(vl &v){
    fl(i, v.size()){
        if (v[i] == 1){
            return i;
        }
    }
    return -1;
}

ll ifp2(vl &v){
    fl(i, v.size()){
        if (v[i] == 2){
            return i;
        }
    }
    return -1;
}

ll ifp0(vl &v){
    fl(i, v.size()){
        if (v[i] == 0){
            return i;
        }
    }
    return -1;
}

ll best_U(string &s){
    ll ans = 0;
    vl v;
    bool flag = false;
    fl(i, s.size()){
        if (i == 0 and s[0] == 'U'){
            int cnt = 0;
            if (s[s.size()-1] == 'U') cnt++;
            if (s[1] == 'U') cnt++;
            v.PB(cnt);
        }
        else if (s[i] == 'D'){
            v.PB(-1);
        }
        else if (i == s.size()-1 and s[i] == 'U'){
            int cnt = 0;
            if (s[s.size()-2] == 'U') cnt++;
            if (s[0] == 'U') cnt++;
            v.PB(cnt);
        }
        else {
            int cnt = 0;
            if (s[i+1] == 'U') cnt++;
            if (s[i-1] == 'U') cnt++;
            v.PB(cnt);
        }
    }
    if (ifp2(v) != -1){
        return ifp2(v);
    }
    else if (ifp1(v) != -1){
        return ifp1(v);
    }
    else if (ifp0(v) != -1){
        return ifp0(v);
    }
    return -1;
}

void flip (string &s, int i){
    if (i >= 0 && i < s.size()) {
        if (s[i] == 'U'){
            s[i] = 'D';
        }
        else {
            s[i] = 'U';
        }
    }
}
void solve(){
    // code here
    d_n(n);
    string s;
    cin >> s;
    int i = 1;
    if (s.size() == 1){
        if(s[0] == 'U'){
            yes
        }
        else {}
        return;
    }
    while (s.size() >= 2){
        if (best_U(s) == -1){
            break;
        }
        int best_index = best_U(s);
        if (best_index == 0){
            flip(s, s.size()-1);
            flip(s, 1);
        }
        else if (best_index == s.size()-1){
            flip(s, s.size()-2);
            flip(s, 0);
        }
        else {
            flip(s, best_index+1);
            flip(s, best_index-1);
        }
        if (best_index >= 0 && best_index < s.size()) {
            s.erase(best_index, 1);
        }
        // cerr << s << en;
        if (s.size() == 1){
            if(s[0] == 'U'){
                i++;
            }
            s = "";
        }
        i++;
    }
    // cerr << en;
    if (i&1) no
    else yes
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

