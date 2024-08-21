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
    vector<int> v(n, 0);
    vi v1(n, 0);
    vi v2(n, 0);
    vl pref1(n, 0);
    vl pref(n, 0);
    vl pref2(n, 0);
    ll cnt = 0;
    fl(i, n){
        cin >> v[i];
        v1[i] = v[i];
        v2[i] = v[i];
    }
    for (int i{n-1}; i>=0; i--){
        pref[i] += cnt+(v[i]^1);
        pref1[i] += cnt+(v[i]^1);
        pref2[i] += cnt+(v[i]^1);
        cnt = pref[i];
    }

    // normal case without flipping
    ll ans = 0;
    fl(i, n){
        if(v[i] == 1){
            ans += pref[i];
        }
    }

    // flipping 0 to 1 from left to right
    ll ans1 = 0;
    fl(i, n){
        if(v1[i]){
            pref1[i]--;
        }
        else {
            v1[i] = 1;
            pref1[i]--;
            break;
        }
    }
    fl(i, n){
        if(v1[i] == 1){
            ans1 += pref1[i];
        }
    }

    // flipping 1 to 0 from right to left
    ll ans2 = 0;
    for (int i{n-1}; i>=0; i--){
        if(v2[i]){
            v2[i] = 0;
            pref2[i]++;
            int tk = i;
            for (int j{tk-1}; j>=0; j--){
                pref2[j]++;
            }
            break;
        }
    }
    fl(i, n){
        if(v2[i] == 1){
            ans2 += pref2[i];
        }
    }

    // maximum of all those numbers

    cout << max(ans, max(ans1, ans2)) << en;
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