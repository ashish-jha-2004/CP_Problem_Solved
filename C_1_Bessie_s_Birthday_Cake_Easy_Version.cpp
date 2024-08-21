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
#define PB(a) push_back(a)
#define PPB pop_back() 
#define MP make_pair
#define B begin()
#define E end()

void solve(){
    // code here
    int n, x, y;
    cin  >> n >> x >> y;
    vl v(x);
    fl(i, x) cin >> v[i];
    sort(v.B, v.E);
    ll sum = x-2;
    ll cnt = 0;
    finl(i, 1, x) {
        if (v[i] - v[i-1] == 2){
            cnt++;
        }
    }
    if(v[x-1] == n-1 and v[0] == 1){
        cnt++;
    }
    if(v[x-1] == n and v[0] == 2){
        cnt++;
    }
    cout << sum + cnt << en;

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