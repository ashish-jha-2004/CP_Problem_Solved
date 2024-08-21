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
#define PB(i) push_back(i)
#define PPB pop_back() 
#define MP make_pair
#define B begin()
#define E end()

void solve(){
    // code here
    ll n;
    cin >> n;
    vl v(n, 0);
    // unordered_map<ll, bool> m;
    fl(i, n){
        // m[i+1] = 0;
        cin >> v[i];
    }
    sort(v.B, v.E);
    bool flag = 1;
    vl ans;
    ans.PB(v[0]);
    finl(i, 1, n){
        if (flag){
            if (v[i]-v[i-1] != 0){
                ans.push_back(v[i]);
            }
        }
    }
    if (ans.size() == 0){
        cout << 1 << en;
        return;
    }
    // sort(ans.B, ans.E);
    ll cnt = 1;
    // ll cnt1 = 0;
    // ll ms = ans[0], me = ans[ans.size()-1];
    for (ll i{0}; i<ans.size(); i++){
        auto a = lower_bound(ans.B, ans.E, ans[i]+n);
        cnt  = max(cnt , a-ans.begin()-i);
        // if (n-i-2 >= 0 and me-ans[n-i-2] <= n-1){
        //     cnt1++;
        // }
    }
    // for (int i{n-2}; i>=0; i--){
    //     if (me-ans[i] <= n-1){
    //         cnt1++;
    //     }
    // }
    cout << cnt << en;

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