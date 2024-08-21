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

void solve(){
    // code here
    int n, m, k;
    cin >> n >> m >> k;
    vl v(n+1);
    v[0] = -1;
    fl(i, n+1){
        if(i == 0) continue;
        int j{0};
        for (; j<m; j++){
            if (i+j < n+1)
                v[i+j] = (j+1);
        }
        i += j-1;
    }
    if (m == 1){
        no
        return;
    }
    vl ans;
    for (int i{1}; i<n+1; i++){
        ans.PB(v[i]);
    }
    vl mi(m+1, 0);
    fl(i, n){
        mi[ans[i]]++;
    }
    ll sum = 0;
    for (int i{2}; i<m+1; i++){
        sum += mi[i];
    }
    if (sum <= k)
        no
    else 
        yes
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