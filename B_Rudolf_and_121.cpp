#include<iostream>
#include<vector>
#include<algorithm>
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
    vector<ll> v(n, 0);
    fl (i, n) cin >> v[i];
    bool flag = true;
    for (int i{n-2}; i>0;) {
        if(v[i+1]*2 > v[i]) {
            no
            return;
        }
        ll temp = v[i+1];
        v[i+1] = 0;
        v[i] -= 2*temp;
        v[i-1] -= temp;
        i--;
    }
    fl(i, n){
        if (v[i] != 0){
            no
            return;
        }
    }
    yes
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