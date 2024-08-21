#include<iostream>
#include<string>
#include<vector>
#include<stack>
using namespace std;

bool is_oppo(int a, int b){
    if (a*-1 == b){
        return true;
    }
    return false;
}

int main(){
    int t;
    cin >> t;
    for (int i{0}; i<t; i++){
        int n;
        cin >> n;
        string s;
        cin >> s;
        vector<int> vec(n, 0);
        for (int j{0}; j<n; j++){
            if (s[j] == '-'){
                vec[j] = -1;
            }
            else if (s[j] == '+'){
                vec[j] = +1;
            }
        }
        stack<int> checker;
        checker.push(vec[0]);
        for (int j{1}; j<n; j++){
            if (!checker.empty() and is_oppo(checker.top(), vec[j])){
                checker.pop();
            }
            else {
                checker.push(vec[j]);
            }
        }
        cout << checker.size() << endl;
    }
}