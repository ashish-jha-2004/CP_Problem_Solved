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
    int n;
    cin >> n;
    vl v(n, 0);
    vl sum(n, 0);
    vl oct(n, 0);
    ll cnt = 0, odc = 0;
    fl(i, n){
        cin >> v[i];
        sum[i] += cnt + v[i];
        cnt = sum[i];
        oct[i] += odc + (v[i]&1);
        odc = oct[i];
    }
    vl oa(n+1, 0);
    oa[0] = 0;
    oa[1] = 1;
    int c = 0;
    int j{0}, k{0};
    for (int i{2}; i<n+1; i++){
        oa[i] = k+c;
        j++;
        if(j == 3){
            j = 0;
            k++;
        }
        c = (c+1)%3;
    }
    fl(i, n){
        if (i == 0){
            cout << v[i] << " ";
        }
        else {
            cout << sum[i]-oa[oct[i]] << " ";
        }
    }
    cout << en;
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