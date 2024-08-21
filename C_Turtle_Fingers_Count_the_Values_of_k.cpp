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

void solve(){
    // code here
    ll a, b, l;
    cin >> a >> b >> l;
    ll cnt = 0;
    vector<bool> m(l+1, 0);
    if (l == 0){
        cout << 1 << en;
        return;
    }
    else {
        long double mka = log(a);
        long double mkb = log(b);
        long double mkl = log(l);
        long double dal = log(l)/log(a);
        long double dbl = log(l)/log(b);
        ll max_y = round(dbl);
        ll max_x = round(dal);
        for (int y{0}; y<=max_y; y++){
            for (int x{0}; x<=max_x; x++){
                ll temp = pow(a, x)*pow(b, y);
                if (temp > l){
                    break;
                }
                if (l%temp == 0 and m[l/temp] == 0){
                    cnt++;
                    m[l/temp] = 1;
                }
            }
        }
        cout << cnt << en;
        return;
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