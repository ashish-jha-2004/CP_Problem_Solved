#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fl(i, j) for(int i{0}; i<j; i++)
#define no cout << "NO\n";
#define yes cout << "YES\n";

void solve(){
    // code here
    int coin{0};
    int n;
    cin >> n;
    vector<char> path(n+1, NULL);
    fl(i, n) cin >> path[i];
    int pos = 0;
    fl(i, n){
        if (path[i+1] == '@'){
            pos++;
            coin++;
        }
        else if (path[i+1] == '.'){
            pos++;
        }
        else if (path[i+1] == '*' and path[i+2] == '*'){
            break;
        }
    }
    cout << coin << endl;
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