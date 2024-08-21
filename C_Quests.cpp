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
    ll n, k;
    cin >> n >> k;
    vl a(n, 0), b(n, 0), sum(n+1, 0), mt(n, 0);
    fl(i, n) cin >> a[i], sum[i+1] = sum[i]+a[i];
    fl(i, n) {
        cin >> b[i];
        if(i == 0){
            mt[i] = b[i];
        }
        else if (mt[i-1] >= b[i]){
            mt[i] = mt[i-1];
        }
        else if (mt[i-1] < b[i]){
            mt[i] = b[i];
        }
    }
    int j = 0;
    ll maxi = 0;
    for (int i{k-1}; i>=0 and j<n; i--){
        maxi = max(maxi, sum[j+1]+(i*mt[j]));
        j++;
    }
    std::cout << maxi << en;
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