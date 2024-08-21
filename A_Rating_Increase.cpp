#include<bits/stdc++.h>
using namespace std;
/*
************************************************************************************************************************************************
    Author :- Ashish Jha
    Yug :- Kaliyug
************************************************************************************************************************************************
    ॐ त्र्यम्बकं यजामहे
    सुगन्धिं पुष्टिवर्धनम् ।
    उर्वारुकमिव बन्धनान्
    मृत्योर्मुक्षीय मामृतात् ॥
************************************************************************************************************************************************
*/

typedef long long ll;
#define fl(i, j) for(int i{0}; i<j; i++)
#define finl(i, j, k) for(int i{j}; i<k; i++)
#define no cout << "NO\n";
#define yes cout << "YES\n";

void solve(){
    // code here
    string s;
    cin >> s;
    pair<int, int> ans{-1, -1};
    for (int i{0}; i<s.length(); i++){
        if (i + 1 < s.length() && s[i+1] != '0'){
            string str1;
            for (int j{0}; j<=i; j++){
                str1.push_back(s[j]);
            }
            string str2;
            for (int j{i+1}; j<s.length(); j++){
                str2.push_back(s[j]);
            }
            int a = stoi(str1);
            int b = stoi(str2);
            if (b > a){
                cout << a << " " << b << endl;
                return;
            }
        }
    }
    cout << ans.first << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--){
        solve();
    }
    return 0;
}