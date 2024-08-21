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
    vector<string> v(2);
    string s1, s2;
    cin >> s1 >> s2;
    v[0] = s1;
    v[1] = s2;
    if (n == 2){
        yes
        return;
    }
    if (v[1][s1.size()-2] != '>'){
        no
        return;
    }
    bool flag = true;
    for (int i{s1.length()-2}; i>=0; i-=2){
        if (!(v[0][i] == '>' or v[1][i] == '>')){
            flag = false;
            break;
        }
    }
    if (flag) yes
    else no

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