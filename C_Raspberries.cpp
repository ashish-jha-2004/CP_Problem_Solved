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
#define fl(i, j) for(int i{0}; i<j; i++)
#define finl(i, j, k) for(int i{j}; i<k; i++)
#define no cout << "NO\n";
#define yes cout << "YES\n";

bool is_zero(vector<int> &v, int k){
    fl(i, v.size()){
        if (v[i]%k == 0){
            return true;
        }
    }
    return false;
}

int closer(vector<int> &v, int k){
    int mini = INT_MAX;
    fl(i, v.size()){
        if (k - (v[i]%k) > 0){
            mini = min(mini, k-(v[i]%k));
        }
    }
    return mini;
}


bool night_eo(vector<int> &v){
    fl(i, v.size()){
        if (!(v[i]&1)){
            return false;
        }
    }
    return true;
}

bool night_oe(vector<int> &v){
    int cnt = 0;
    fl(i, v.size()){
        if (!(v[i]&1)){
            cnt++;
        }
    }
    if (cnt == 1){
        return true;
    }
    return false;
}

bool night_te(vector<int> &v){
    int cnt = 0;
    fl(i, v.size()){
        if (!(v[i]&1)){
            cnt++;
        }
    }
    if (cnt >= 2){
        return true;
    }
    return false;
}

void solve(){
    // code here
    int n, k;
    cin >> n >> k;
    vector<int> v(n, 0);
    fl(i, n) cin >> v[i];
    if (k != 4){
        if (is_zero(v, k)){
            cout << 0 << endl;
            return;
        }
        else{
            cout << closer(v, k) << endl;
        }
    }
    else {
        if (night_eo(v)){
            cout << min(closer(v, 4), 2) << endl;
        }
        else if (night_oe(v)){
            if (is_zero(v, 4)){
                cout << 0 << endl;
            }
            else {
                cout << 1 << endl;
            }
        }
        else if (night_te(v)){
            cout << 0 << endl;
        }
    }
    return;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--){
        solve();
    }
    return 0;
}