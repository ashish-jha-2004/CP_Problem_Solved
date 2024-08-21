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
#define fn(i, j, k) for(int i{j}; i<k; i++)
#define no cout << "NO\n";
#define yes cout << "YES\n";
#define sort(v) sort(v.begin(), v.end())
#define d_n(n) ll n; cin >> n
#define d_v(v, n) vl v(n); fl(i, n) cin >> v[i];
#define en "\n"
#define F first
#define S second
#define PB(a) push_back(a)
#define PPB pop_back()
#define MP make_pair
#define B begin()
#define E end()

// Golobal Variables
const int N = 1e7;
int arr[N+7];


void solve(){
    // code here
    int n, k;
    cin >> n >> k;
    if (k == 1){
        fl(i, n){
            cout << i+1 << " ";
        }
        cout << en;
        return;
    }
    if (n == k){
        fl(i, n){
            cout << 1 << " ";
        }
        cout << en;
        return;
    }
    else {
        cout << "-1" << en;
        return;
    }

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    d_n(t);
    while (t--){
        solve();
    }
    return 0;
}