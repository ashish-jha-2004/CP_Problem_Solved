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
    vi v(n, 0);
    multiset<int> ms;
    fl(i, n) {
        cin >> v[i];
        ms.insert(v[i]);
    }
    int cnt = 0;
    fl(i, n){
        if(ms.find(v[i]) != ms.end()){
            
            auto it = ms.find(v[i]);
            bool awk = ms.find((*it)^2147483647) != ms.end();
            if(awk){
                cnt++;
                ms.erase(ms.find((*it)^2147483647));
                ms.erase(ms.find(v[i]));
            }
            else{
                cnt++;
                ms.erase(ms.find(v[i]));
            }
        }
    }
    std::cout << cnt << en;
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