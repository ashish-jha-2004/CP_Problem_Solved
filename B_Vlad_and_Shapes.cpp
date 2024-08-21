#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fl(i, j) for(int i{0}; i<j; i++)
#define no cout << "NO\n";
#define yes cout << "YES\n";

void solve(){
    // code here
    int n;
    cin >> n;
    vector<string> box(n);
    for (int i{0}; i<n; i++){
        for (int j{0}; j<n; j++){
            cin >> box[i][j];
        }
    }
    vector<int> cnt(n, 0);
    for (int i{0}; i<n; i++){
        for (int j{0}; j<n; j++){
            if (box[i][j] == '1'){
                ++cnt[i];
            }
        }
    }
    for(int i{0}; i<n-1; i++){
        if (cnt[i] != 0 and cnt[i] == cnt[i+1]){
            cout << "SQUARE\n";
            return;
        }
    }
    cout << "TRIANGLE\n";
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