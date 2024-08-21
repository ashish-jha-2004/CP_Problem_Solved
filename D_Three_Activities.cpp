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

bool cmp(int x, int y) {
    return (x < y);
}

void solve(){
    // code here
    int n;
    cin >> n;
    vl va(n, 0), vb(n, 0), vc(n, 0);
    fl(i, n) cin >> va[i];
    fl(i, n) cin >> vb[i];
    fl(i, n) cin >> vc[i];

    // for 1 -> 2 -> 3
    int not_1 = max_element(va.B, va.E) - va.B;
    // cerr << not_1 << en;
    ll ax1 = *max_element(va.B, va.E);
    ll bx1 = -1;
    for (ll i{0}; i<n; i++){
        if (i == not_1){
            continue;
        }
        bx1 = max(bx1, vb[i]);
    }
    int not_2 = -1;
    fl(i, n){
        if (vb[i] == bx1 and i != not_1){
            not_2 = i;
            break;
        }
    }
    ll cx1 = -1;
    fl(i, n){
        if (i == not_1 or i == not_2){
            continue;
        }
        cx1 = max(cx1, vc[i]);
    }
    ll ans1 = ax1+bx1+cx1;

    // for 1 -> 3 -> 2
    int not_12 = max_element(va.B, va.E) - va.B;
    ll ax12 = *max_element(va.B, va.E);
    ll cx12 = -1;
    for (ll i{0}; i<n; i++){
        if (i == not_12){
            continue;
        }
        cx12 = max(cx12, vc[i]);
    }
    int not_32 = -1;
    fl(i, n){
        if (vc[i] == cx12 and i != not_12){
            not_32 = i;
            break;
        }
    }
    ll bx12 = -1;
    fl(i, n){
        if (i == not_12 or i == not_32){
            continue;
        }
        bx12 = max(bx12, vb[i]);
    }
    ll ans2 = ax12+bx12+cx12;
    // cerr << ans2 << en;

    // for 2 -> 1 -> 3
    int not_20 = max_element(vb.B, vb.E) - vb.B;
    ll bx11 = *max_element(vb.B, vb.E);
    ll ax11 = -1;
    for (ll i{0}; i<n; i++){
        if (i == not_20){
            continue;
        }
        ax11 = max(ax11, va[i]);
    }
    int not_10 = -1;
    fl(i, n){
        if (va[i] == ax11 and i != not_20){
            not_10 = i;
            break;
        }
    }
    ll cx11 = -1;
    fl(i, n){
        if (i == not_10 or i == not_20){
            continue;
        }
        cx11 = max(cx11, vc[i]);
    }
    ll ans3 = ax11+bx11+cx11;
    // cerr << ans3 << en;

    // for 2 -> 3 -> 1
    int not_202 = max_element(vb.B, vb.E) - vb.B;
    ll bx112 = *max_element(vb.B, vb.E);
    ll cx112 = -1;
    for (ll i{0}; i<n; i++){
        if (i == not_202){
            continue;
        }
        cx112 = max(cx112, vc[i]);
    }
    int not_302 = -1;
    fl(i, n){
        if (vc[i] == cx112 and i != not_202){
            not_302 = i;
            break;
        }
    }
    ll ax112 = -1;
    fl(i, n){
        if (i == not_302 or i == not_202){
            continue;
        }
        ax112 = max(ax112, va[i]);
    }
    ll ans4 = ax112+bx112+cx112;
    // cerr << ans4 << en;
    
    // for 3 -> 1 -> 2
    int not_300 = max_element(vc.B, vc.E) - vc.B;
    ll cx111 = *max_element(vc.B, vc.E);
    ll ax111 = -1;
    for (ll i{0}; i<n; i++){
        if (i == not_300){
            continue;
        }
        ax111 = max(ax111, va[i]);
    }
    int not_100 = -1;
    fl(i, n){
        if (va[i] == ax111 and not_300 != i){
            not_100 = i;
            break;
        }
    }
    ll bx111 = -1;
    fl(i, n){
        if (i == not_100 or i == not_300){
            continue;
        }
        bx111 = max(bx111, vb[i]);
    }
    ll ans5 = ax111+bx111+cx111;

    // for 3 -> 2 -> 1
    int not_3002 = max_element(vc.B, vc.E) - vc.B;
    ll cx1112 = *max_element(vc.B, vc.E);
    ll bx1112 = -1;
    for (ll i{0}; i<n; i++){
        if (i == not_3002){
            continue;
        }
        bx1112 = max(bx1112, vb[i]);
    }
    int not_2002 = -1;
    fl(i, n){
        if (vb[i] == bx1112 and i != not_3002){
            not_2002 = i;
            break;
        }
    }
    ll ax1112 = -1;
    fl(i, n){
        if (i == not_2002 or i == not_3002){
            continue;
        }
        ax1112 = max(ax1112, va[i]);
    }
    ll ans6 = ax1112+bx1112+cx1112;

    cout << max({ans1, ans2, ans3, ans4, ans5, ans6}, cmp) << en;
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