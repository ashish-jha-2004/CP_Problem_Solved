#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

bool joi(string s1, string s2){
    int l_cnt_s1 = 0, l_cnt_s2 = 0, o_cnt_s1 = 0, o_cnt_s2 = 0;
    for (int i{0}; i<s1.length(); i++){
        if (s1[i] == 'L'){
            l_cnt_s1++;
        }
        else {
            o_cnt_s1++;
        }
    }
    for (int i{0}; i<s2.length(); i++){
        if (s2[i] == 'L'){
            l_cnt_s2++;
        }
        else {
            o_cnt_s2++;
        }
    }
    if (l_cnt_s1 != l_cnt_s2 and o_cnt_s1 != o_cnt_s2){
        return true;
    }
    return false;
}

int main(){
    int t;
    cin >> t;
    string s;
    cin >> s;
    int me = 0;
    int ans = -1;
    for (int i{0}; i<s.length(); i++){
        string s1, s2;
        for (int j{0}; j<=me; j++){
            s1.push_back(s[j]);
        }
        for (int j{me+1}; j<s.length(); j++){
            s2.push_back(s[j]);
        }
        if (s1.length() != 0 and s2.length() != 0 and joi(s1, s2)){
            ans = s1.length();
            break;
        }
        me++;
    }
    cout << ans << endl;
}
