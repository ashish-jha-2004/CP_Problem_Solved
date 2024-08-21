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
#define PB(n) push_back(n)
#define PPB pop_back() 
#define MP make_pair
#define B begin()
#define E end()

void solve(){
    // code here
    ll n, k;
    cin >> n >> k;
    vl a(n, 0), x(n, 0);
    fl(i, n) cin >> a[i];
    fl(i, n) {
        cin >> x[i];
    }
    vl left(n+1, 0), right(n+1, 0);
    ll itl = 1, itr = 1;
    for (int i{0}; i<n; i++){
        if(x[i] < 0){
            left[-1*x[i]] = a[i];
        }
        else {
            right[x[i]] = a[i];
        }
    }
    ll carry = k;
    for (ll i{1}; i<n+1; i++){
        if(left[itl] != 0 and right[itr] != 0){
            if (carry-left[itl]-right[itl]  >= 0){
                carry -= left[itl];
                carry -= right[itr];
                itr++;
                itl++;
            }
            else {
                no
                return;
            }
            
        }
        else if(left[itl] != 0 and right[itr] == 0){
            if (carry-left[itl] >= 0){
                carry -= left[itl];
                itl++;
                itr++;
            }
            else {
                no
                return;
            }
        }
        else if(left[itl] == 0 and right[itr] != 0){
            if (carry-right[itr] >= 0){
                carry -= right[itr];
                itl++;
                itr++;
            }
            else {
                no
                return;
            }
        }
        else {
            itl++;
            itr++;
        }
        carry += k;
    }
    yes
    return;
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