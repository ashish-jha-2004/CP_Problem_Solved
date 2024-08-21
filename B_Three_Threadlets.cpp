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
    vector<int> v(3, 0);
    fl(i, 3) cin >> v[i];
    sort(v.begin(), v.end());
    if(v[0] == v[2]) {
        yes
        return;
    }
    if(v[2]%v[0] == 0 and v[1]%v[0] == 0){
        int a = v[2]/v[0];
        int b = v[1]/v[0];
        if(a+b <= 5){
            yes
            return;
        }
        else {
            no 
            return;
        }
    }
    no
    return;
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