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
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<char> vc;
typedef pair<int, int> pii;
typedef pair<int, char> pic;
#define fl(i, j) for(int i{0}; i<j; i++)
#define finl(i, j, k) for(int i{j}; i<k; i++)
#define no cout << "NO\n";
#define yes cout << "YES\n";
#define en "\n"
#define F first
#define S second
#define PB push_back()
#define PPB pop_back() 
#define MP make_pair
#define B begin()
#define E end()

int c_m(int n, int k){
    int rem = n%k;
    return n-rem+k;
}

void solve(){
    // code here
    int n;
    cin >> n;
    vector<int> temp(n, 0);
    fl(i, n) cin >> temp[i];
    if(n == 1){
        cout << temp[0] << en;
        return;
    }
    int cnt = 0;
    int prev = temp[0];
    int c;
    for (int i{1}; i<n; i++){
        c = c_m(prev, temp[i]);
        prev = c;
    }
    cout << c << en;

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--){
        solve();
    }
    return 0;
}