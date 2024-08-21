#include<bits/stdc++.h>

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
    int n;
    std::cin >> n;
    std::string s;
    std::cin >> s;
    std::vector<int> ans(26, 0);
    for (int i{0}; i<n; i++){
        ans[s[i]-'A'] += 1;
    }
    int cnt = 0;
    for (int i{0}; i<26; i++){
        if(ans[i] >= i+1){
            cnt++;
        }
    }
    std::cout << cnt << std::endl;
}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    int t;
    std::cin >> t;
    while (t--){
        solve();
    }
    return 0;
}