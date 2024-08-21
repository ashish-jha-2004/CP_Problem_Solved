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

bool cv(char i){
    if (i == 'a' or i == 'e'){
        return true;
    }
    return false;
}

void solve(){
    // code here
    int n;
    cin >> n;
    string s;
    cin >> s;
    for (int i{1}; i<n;){
        if (i == n-1 or i == n-2){
            if (i == n-1){
                cout << s[i-1] << s[i] << en;
            }
            if (i == n-2){
                cout << s[i-1] << s[i] << s[i+1] << en;
            }
            break;
        }
        if (cv(s[i]) and cv(s[i+2])){
            cout << s[i-1] << s[i] << ".";
            i += 2;
            continue; 
        }
        if (!cv(s[i+2])){
            cout << s[i-1] << s[i] << s[i+1] << ".";
            i += 3;
            continue;
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