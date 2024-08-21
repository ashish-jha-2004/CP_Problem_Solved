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
#define sortall(v) sort(v.begin(), v.end())
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

void solve(){
    // code here
    string s1, s2;
    bool a = true;
    cin >> s1 >> s2;
    string s3 = max(s1, s2);
    string s4 = min(s1, s2);
    fl(i, min(s4.size(), s3.size())){
        if (a and s3[i] > s4[i]){
            a = false;
        }
        else if (!a){
            if (s3[i] >= s4[i]){
                char temp = s3[i];
                s3[i] = s4[i];
                s4[i] = temp;
            }
        }
    }
    cout << s3 << en << s4 << en;

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