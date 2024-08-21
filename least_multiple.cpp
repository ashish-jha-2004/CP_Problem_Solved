#include<iostream>
#include<vector>
using namespace std;

bool is_positive(vector<long long> &v){
    int cnt = 0;
    for (int i{0}; i<v.size(); i++){
        if (v[i] > 0){
            cnt++;
        }
    }
    if (cnt == v.size()){
        return true;
    }
    return false;
}

bool is_zandn(vector<long long> &v){
    int cnt = 0;
    for (int i{0}; i<v.size(); i++){
        if (v[i] == 0){
            return true;
        }
        if (v[i] < 0){
            cnt++;
        }
    }
    if (cnt%2 != 0){
        return true;
    }
    return false;
}

int main(){
    int t;
    cin >> t;
    int n;
    while (cin >> n){
        vector<long long> v(n);
        for (int i{0}; i<n; i++){
            cin >> v[i];
        }
        if (is_positive(v)){
            cout << "1" << endl;
            cout << "1" << " " << "0" << endl;
        }
        else if(is_zandn(v)){
            cout << "0" << endl;
        }
        else {
            cout << "1" << endl;
            cout << "1" << " " << "0" << endl;
        }
    }
}