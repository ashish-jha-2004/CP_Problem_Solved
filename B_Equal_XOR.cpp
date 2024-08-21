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
typedef pair<int, int> pii;
typedef pair<int, char> pic;
#define fl(i, j) for(int i{0}; i<j; i++)
#define finl(i, j, k) for(int i{j}; i<k; i++)
#define no cout << "NO\n";
#define yes cout << "YES\n";
#define en "\n"
#define F first
#define S second
#define PB push_back
#define MP make_pair

void solve(){
    // code here
    int n, k;
    cin >> n >> k;
    vector<ll> v(2*n, 0);
    vector<bool> v1(2*n+1, 0);
    vector<bool> v2(2*n+1, 0);
    vector<ll> l(n, 0), r(n, 0);
    fl(i, 2*n){
        cin >> v[i];
        if (i < n){
            l[i] = v[i];
            v1[v[i]] = 1;
        }
        if (i >= n and i < 2*n){
            r[i-n] = v[i];
            v2[v[i]] = 1;
        }
    }
    vector<ll> ans1, ans2;
    ll temp = 2*k;
    
    int no_of_it = 0;
    fl(i, n){
        if (v1[l[i]] and !v2[l[i]]){
            ans1.push_back(l[i]);
            ans1.push_back(l[i]);
            v1[l[i]] = 0;
            temp--;
            temp--;
            no_of_it++;
        }
        if (temp == 0){
            break;
        }
    }
    fl(i, n){
        if (v2[r[i]] and !v1[r[i]]){
            ans2.push_back(r[i]);
            ans2.push_back(r[i]);
            v2[r[i]] = 0;
            no_of_it--;
        }
        if (no_of_it == 0){
            break;
        }
    }

    fl(i, n){
        if (v1[l[i]] and v2[l[i]]){
            ans1.PB(l[i]);
            ans2.PB(l[i]);
            v1[l[i]] = 0;
            v2[l[i]] = 0;
            temp--;
        }
        if (temp == 0){
            break;
        }
    }

    fl(i, 2*k){
        cout << ans1[i] << " ";
    }
    cout << en;
    fl(i, 2*k){
        cout << ans2[i] << " ";
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