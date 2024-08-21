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

void solve(){
    // code here
    int n, m, x;
    cin >> n >> m >> x;
    unordered_set<int> ans;
    ans.insert(x);
    for (int i{0}; i<m; i++){
        int s;
        char ch;
        cin >> s >> ch;
        if(ch == '0'){
            unordered_set<int> temp;
            for (auto it: ans){
                it += s;
                if (it > n){
                    it -= n;
                }
                temp.insert(it);
            }
            ans = temp;
        }
        else if (ch == '1'){
            unordered_set<int> temp;
            for (auto it: ans){
                it = it+n-s;
                if (it > n){
                    it -= n;
                }
                temp.insert(it);
            }
            ans = temp;
        }
        else{
            unordered_set<int> temp;
            for (auto it: ans){
                it += s;
                if (it > n){
                    it -= n;
                }
                temp.insert(it);
            }
            for (auto it: ans){
                it = it+n-s;
                if (it > n){
                    it -= n;
                }
                temp.insert(it);
            }
            ans = temp;
        }
    }
    cout << ans.size() << endl;
    vector<int> as(ans.size(), 0);
    int i=0;
    for (auto k : ans){
        as[i] = k;
        i++;
    }
    sort(as.begin(), as.end());
    for (auto o: as){
        cout << o << " ";
    }
    cout << endl;
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