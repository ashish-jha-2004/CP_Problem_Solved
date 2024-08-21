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

void change_b(vector<char> &v, vector<pair<ll, char>> &v_b){
    if (v_b.empty()){
        return;
    }
    v[v_b[v_b.size()-1].first] = '$';
    v_b.pop_back();
}

void change_B(vector<char> &v, vector<pair<ll, char>> &v_B){
    if (v_B.empty()){
        return;
    }
    v[v_B[v_B.size()-1].first] = '$';
    v_B.pop_back();
}

void solve(){
    // code here
    string str;
    cin >> str;
    vector<char> v;
    vector<pair<ll, char>> v_b, v_B;
    fl(i, str.length()){
        if (str[i] != 'b' and str[i] != 'B'){
            v.push_back(str[i]);
            if (str[i] >= 97 and str[i] <= 122){
                v_b.push_back({v.size()-1, str[i]});
            } 
            else if (str[i] >= 65 and str[i] <= 90){
                v_B.push_back({v.size()-1, str[i]});
            }
        }
        else if (str[i] == 'b'){
            change_b(v, v_b);
        }
        else{
            change_B(v, v_B);
        }
    }
    if (v.empty()){
        cout << endl;
        return;
    }
    fl(i, v.size()){
        if (v[i] != '$') cout << v[i];
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