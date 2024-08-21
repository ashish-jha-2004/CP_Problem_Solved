#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vl;
#define fl(i, j) for(int i{0}; i<j; i++)
#define fn(i, j, k) for(int i{j}; i<k; i++)
#define d_n(n) ll n; cin >> n
#define d_v(v, n) vl v(n); fl(i, n) cin >> v[i];
#define en "\n"

ll no_w(vl &v, int yc){
    ll win = 0;
    ll temp = 0;
    fl(i, v.size()){
        if (v[i] > yc){
            break;
        }
        else if (v[i] == yc){
            temp = i;
            break;
        }
    }
    if (temp != 0){
        win = 1;
    }
    else if (temp == 0){
        win = 0;
    }
    if (temp+1 < v.size()){
        for (int i{temp+1}; i<(int)v.size(); i++){
            if (v[i] > yc){
                break;
            }
            win++;
        }
    }
    return win;
}

void solve(){
    // code here
    d_n(n);
    d_n(k);
    vl v(n);
    fl(i, n){
        cin >> v[i];
    }
    ll yc = v[k-1];
    ll cntl = 0;
    fl(i, n){
        if (v[i] > yc){
            break;
        }
        cntl++;
    }
    ll max1 = 0, max2 = 0, max3 = 0, max4 = 0;
    if (k >= cntl){
        swap(v[0], v[k-1]);
        max1 = no_w(v, yc);
        swap(v[0], v[k-1]);
        swap(v[cntl], v[k-1]);
        max2 = no_w(v, yc);
    }
    else {
        max3 = no_w(v, yc);
        if (k-1 != 0){
            swap(v[0], v[k-1]);
            max4 = no_w(v, yc);
        }
    }
    cout << max(max1, max(max2, max(max3, max4))) << en;
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