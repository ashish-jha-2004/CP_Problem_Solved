#include<iostream>
#include<string>
using namespace std;
#define ll long long

pair<int, int> first_black(string s){
    pair<int, int> ans = make_pair(0, s.length()-1);
    for (int i{0}; i<s.length(); i++){
        if (s[i] == 'B'){
            ans.first = i;
            break;
        }
    }
    for (int i{s.length()-1}; i>=0; i--){
        if (s[i] == 'B'){
            ans.second = i;
            break;
        }
    }
    return ans;
}

int main(){
    int t;
    cin >> t;
    int n;
    while(cin >> n){
        string s;
        cin >> s;
        pair<int, int> str = first_black(s);
        cout << str.second-str.first+1 << endl;
    }
    return 0;
}