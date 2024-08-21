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

bool is_possible(vector<int> a){
    sort(a.begin(), a.end());
    vector<int> temp;
    int cnt = 0;
    for (int i{1}; i<a.size(); ) {
        int j = i;
        while (j<a.size() and a[j-1] == a[j]){
            cnt++;
            j++;
        }
        if (j < a.size()-1)
            i = j+1;
        if(cnt != 0){
            temp.push_back(cnt);
        }
        if (j >= a.size()-1){
            break;
        }
        cnt = 0;
    }
    if (temp.empty()){
        return false;
    }
    else if (temp.size() == 1){
        return false;
    }
    return true;
}

void solve(){
    // code here
    int n; cin >> n;
    vector<int> a, b(n, 1);
    fl(i, n){
        int x;
        cin >> x;
        a.push_back(x);
    }
    bool flag = true;
    if (!is_possible(a)){
        cout << "-1" << endl;
    }
    else {
        for (int i{0}; i<n; i++){
            if (b[i] == 1){
                for (int j{i+1}; j<n; j++){
                    if (a[i] == a[j] and flag){
                        b[i] = 1;
                        b[j] = 2;
                        for (int k{j+1}; k<n; k++){
                            if (a[j] == a[k]){
                                b[k] = 2;
                            }
                        }
                        flag = false;
                        break;
                    }
                    else if (a[i] == a[j] and !flag){
                        b[i] = 1;
                        b[j] = 3;
                        for (int k{j+1}; k<n; k++){
                            if (a[j] == a[k]){
                                b[k] = 3;
                            }
                        }
                        flag = true;
                        break;
                    }
                }
            }
            
        }
        fl(i, n){
            cout << b[i] << " ";
        }
        cout << endl;
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