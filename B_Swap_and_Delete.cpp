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
    string s;
    cin >> s;
    if (s.size() == 1){
        cout << 1 << en;
        return;
    }
    int cnt0=0, cnt1=0;
    fl(i, s.size()){
        if (s[i] == '0'){
            cnt0++;
        }
        else{
            cnt1++;
        }
    }
    if (cnt0 == cnt1){
        cout << 0 << en;
        return;
    }
    // ll temp = max(cnt1, cnt0) - min(cnt1, cnt0);
    fl(i, s.size()){
        if (s[i] == '0' and cnt1 > 0){
            cnt1--;
        }
        else if (s[i] == '1' and cnt0 > 0){
            cnt0--;
        }
        else {
            break;
        }
    }
    cout << cnt1+cnt0 << en;

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