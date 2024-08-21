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

bool mod1(vl v, int n){
    fl(i, n){
        if(v[i]%3 == 1){
            return true;
        }
    }
    return false;
}

void solve(){
    // code here
    int n;
    cin >> n;
    vl v(n, 0);
    ll sum = 0;
    fl(i, n) {
        cin >> v[i];
        sum += v[i];
    }
    if (n == 1){
        if (sum%3 != 0){
            cout << 1 << en;
            return;
        }
        else {
            cout << 0 << en;
            return;
        }
    }
    if(sum%3 == 0){
        cout << 0 << en;
        return;
    }
    else if(sum%3 == 2){
        cout << 1 << en;
        return;
    }
    else {
        if(mod1(v, n)){
            cout << 1 << en;
        }
        else {
            cout << 2 << en;
        }
    }

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