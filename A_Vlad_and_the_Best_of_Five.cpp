#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fl(i, j) for(int i{0}; i<j; i++)
#define no cout << "NO\n";
#define yes cout << "YES\n";

void solve(){
    // code here
    vector<char> s(6, NULL);
    int a_cnt = 0, b_cnt = 0;
    fl(i, 5) cin >> s[i];
    fl(i, 5){
        if (s[i] == 'A') a_cnt++;
        else if (s[i] == 'B') b_cnt++;
    }
    if (a_cnt > b_cnt){
        cout << "A" << endl;
    }
    else {
        cout << "B" << endl;
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