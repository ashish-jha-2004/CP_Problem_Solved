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

typedef unsigned long long int ll;
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
#define MOD 10000007

void solve(){
    // code here
    ll n, m;
    cin >> n >> m;
    string s;
    ll prod = 1;
    deque<ll> dq;
    fl(i, n){
        ll x;
        cin >> x;
        prod *= x%m;
        dq.push_back(x);
    }
    cin >> s;
    int i = 0;
    while (!dq.empty()){
        cout << prod % m<< " ";
        if (s[i] == 'L'){
            ll temp = dq.front();
            dq.pop_front();
            prod /= (temp%m);
        }
        else {
            ll temp = dq.back();
            dq.pop_back();
            prod /= (temp%m);
        }
        i++;
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