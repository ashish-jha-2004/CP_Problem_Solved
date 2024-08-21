#include<iostream>
#include<string>
#include<unordered_map>
#include<vector>
using namespace std;

#define ll long long

int main(){
    int t;
    cin >> t;
    int n;
    while (cin >> n){
        vector<int> trace(n);
        for (int i{0}; i<n; i++){
            cin >> trace[i];
        }
        unordered_map<char, int> uttar;
        for (char ch = 'a'; ch <= 'z'; ch++){
            uttar.insert({ch, 0});
        }
        string ans = "";
        for (int i{0}; i<n; i++){
            for (auto j: uttar){
                if (j.second == trace[i]){
                    ans += j.first; 
                    uttar[j.first]++;
                    break;
                }
            }
        }
        cout << ans << endl;
    }
}