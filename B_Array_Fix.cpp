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

bool is_sorted(vector<int> v, int k){
    vector<int> temp;
    for (int i{v.size()-1}; i>=k; i--){
        temp.push_back(v[i]);
    }
    sort(temp.begin(), temp.end());
    for (int i{v.size()-1}; i>=k; i--){
        if(temp[i-k] != v[i]){
            return false;
        }
    }
    return true;
}

void solve(){
    // code here
    int n;
    cin >> n;
    vector<int> v(n, 0);
    fl(i, n) cin >> v[i];
    int ans = -1;
    for (int i{n-1}; i>=0; i--){
        if (!is_sorted(v, i)){
            ans = i;
            break;
        }
    } 
    vector<int> v1;
    for (int i{0}; i<=n-1; i++){
        if(v[i] >= 10 and i<=ans){
            v1.push_back(v[i]/10);
            v1.push_back(v[i]%10);
        }
        else {
            v1.push_back(v[i]);
        }
    }
    if (is_sorted(v1, 0)){
        yes
    }
    else {
        no
    }
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