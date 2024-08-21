#include<iostream>
#include<string>
#include<vector>
using namespace std;

int main(){
    int n;
    cin >> n;
    while (cin >> n){
        int k;
        cin >> k;
        vector<char> alphabet;
        for (char ch = 'a'; ch <= 'z'; ++ch) {
            alphabet.push_back(ch);
        }
        vector<char> s;
        for (int i{0}; i<k; i++){
            s.push_back(alphabet[i]);
        }
        vector<vector<char>> ans;
        for (int j{0}; j<n; j++){
            ans.push_back(s);
        }
        for (int l{0}; l<ans.size(); l++){
            for (int m{0}; m<ans[l].size(); m++)
            cout << ans[l][m];
        }
        cout << endl;
    }
}
