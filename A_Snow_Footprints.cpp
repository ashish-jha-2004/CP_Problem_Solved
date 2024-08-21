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
    int n;
    cin >> n;
    string s;
    cin >> s;
    int start, last;
    bool flag = true;
    for(int i{0}; i<n; i++){
        if (s[i] == 'R' and flag){
            start = i+1;
            flag = false;
        }
        if (s[i] == 'R' and s[i+1] == 'L'){
            last = i+1;
            break;
        }
        if (s[i] == 'R' and s[i+1] == '.'){
            last = i+2;
            break;
        }
        if (flag and s[i] == 'L'){
            last = i;
            flag = false;
        }
        if (s[i] == 'L' and s[i+1] != 'L'){
            start = i+1;
            break;
        }
    }
    cout << start << " " << last;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}