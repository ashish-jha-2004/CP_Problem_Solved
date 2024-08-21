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
    int n;
    cin >> n;
    string s;
    cin >> s;
    int ans = 0;
    vector<bool> v(n, 0);
    for (int i{0}; i<=n-1; i++){
        if(!v[i] and s[i] == 'A' and s[i+1] == 'B'){
            swap(s[i], s[i+1]);
            v[i] = 1;
            ans++;
            for (int j{i}; !v[j-1]; j--){
                if(!v[j-1] and s[j] == 'B' and s[j-1] == 'A'){
                    swap(s[j], s[j-1]);
                    v[j-1] = 1;
                    ans++;
                }
            }
        }
    }
    cout << ans << endl;
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