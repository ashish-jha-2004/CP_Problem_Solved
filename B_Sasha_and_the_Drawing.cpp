#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fl(i, j) for(int i{0}; i<j; i++)
#define no cout << "NO\n";
#define yes cout << "YES\n";

void solve(){
    // code here
    ll n, k;
    cin >> n >> k;
    if (k == 4*n-2){
        cout << 2*n << endl;
        return;
    }
    else if (k == 4*n-3){
        cout << 2*n-1 << endl;
        return;
    }
    else {
        if (!(k&1)){
            ll temp = 4*n-4;
            ll cnt = 2*n-2;
            while (temp != k){
                cnt--;
                temp -= 2;
            }
            cout << cnt << endl;
            return;
        }
        else {
            ll temp = 4*n-5;
            ll cnt = 2*n-2;
            while (temp != k){
                cnt--;
                temp -= 2;
            }
            cout << cnt << endl;
            return;
        }
    }

}

int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--){
        solve();
    }
    return 0;
}