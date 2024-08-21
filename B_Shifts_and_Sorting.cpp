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

pair<ll, ll> t0(string &s, int i, int n){
    pair<ll, ll> ans;
    ans.first = -1;
    ll sum = 0;
    fn(j, i, n){
        if (s[j] == '0'){
            sum += 1;
        }
        if (j == n-1 and s[j] == '0'){
            ans.first = n-1;
            break;
        }
        if (s[j] == '0'){
            ans.first = j;
            break;
        }
    }
    ans.second = sum;
    return ans;
}

void solve(){
    // code here
    string s;
    cin >> s;
    ll n = s.size();
    string temp = s;
    sortall(temp);
    if (s == temp){
        cout << 0 << en;
        return;
    }

    ll s1 = 0;
    ll e0 = 0;
    fl(i, n){
        if (s[i] == '1'){
            s1 = i;
            break;
        }
    }
    ll num = 0;
    ll ans = 0;
    e0 = t0(s, s1, n).first;
    num = t0(s, s1, n).second;
    // cerr << e0 << en;
    while (e0 != -1){
        ans += num + num*e0 - (num*s1 + (num*(num - 1))/2);
        s1 += num;
        if (e0 < n-1)
            num = t0(s, e0+1, n).second;
        e0 = t0(s, e0+1, n).first;
    }
    cout << ans << en;
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