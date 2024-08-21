#include<bits/stdc++.h>
using namespace std;

void solve() {
    string s;
    cin >> s;
    vector<int> v;
    int cnt_zero = 0, cnt_one = 0;
    for (int i{0}; i<s.size(); i++){
        if (s[i] == '0'){
            cnt_zero++;
        }
        else if(s[i] == '1'){
            cnt_one++;
        }
        v.push_back(s[i]-'0');
    }
    int cnt = 0;
    for (int i{0}; i<v.size(); i++){
        if (v[i] == 0 and cnt_one > 0){
            cnt_one--;
        }
        else if (v[i] == 1 and cnt_zero > 0){
            cnt_zero--;
        }
        else {
            cnt++;
            cnt_one = -100000;
            cnt_zero = -100000;
        }
    }
    cout << cnt << endl;
}

int main() {
    int t;
    cin >> t;
    while(t--) {
      solve();
    }
    return 0;
}
