#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fl(i, j) for(int i{0}; i<j; i++)
#define no cout << "NO\n";
#define yes cout << "YES\n";

void solve(){
    // code here
    int a, b, c;
    cin >> a >> b >> c;
    if (((a&1) and (b&1) and !(c&1)) || ((c&1) and (b&1) and !(a&1)) || ((a&1) and (c&1) and !(b&1))){
        if ((a&1) and (b&1) and !(c&1)){
            cout << "0 0 1" << endl;
        }
        else if ((c&1) and (b&1) and !(a&1)){
            cout << "1 0 0" << endl;
        }
        else {
            cout << "0 1 0" << endl;
        }
    }
    else if ((!(a&1) and !(b&1) and (c&1)) || (!(c&1) and !(b&1) and (a&1)) || (!(a&1) and !(c&1) and (b&1))){
        if (!(a&1) and !(b&1) and (c&1)){
            cout << "0 0 1" << endl;
        }
        else if (!(c&1) and !(b&1) and (a&1)){
            cout << "1 0 0" << endl;
        }
        else {
            cout << "0 1 0" << endl;
        }
    }
    else {
        cout << "1 1 1" << endl;
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