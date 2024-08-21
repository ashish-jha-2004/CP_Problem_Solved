#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fl(i, j) for(int i{0}; i<j; i++)
#define no cout << "NO\n";
#define yes cout << "YES\n";

void solve(){
    // code here
    vector<string> v;
    fl (i, 3) {
        string s;
        cin >> s;
        v.push_back(s);
    }
    int temp = 0;
    fl (i, 3){
        fl (j, 3){
            if (v[i][j] == '?'){
                temp = i;
            }
        }
    }
    bool flag = 1;
    char one, two;
    fl (i, 3){
        if (v[temp][i] != '?' and flag == true){
            one = v[temp][i];
            flag = false;
        }
        else if (v[temp][i] != '?'){
            two = v[temp][i];
        }
    }
    if ((one == 'A' and two == 'B') or (one == 'B' and two == 'A')){
        cout << 'C' << endl;
    }
    else if ((one == 'A' and two == 'C') or (one == 'C' and two == 'A')){
        cout << 'B' << endl;
    }
    else if ((one == 'C' and two == 'B') or (one == 'B' and two == 'C')){
        cout << 'A' << endl;
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