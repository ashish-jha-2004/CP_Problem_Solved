#include<iostream>
#include<vector>
#include<stdlib.h>
#include<climits>
using namespace std;

int main(){
    int t;
    cin >> t;
    for (int i{0}; i<t; i++){
        int n;
        cin >> n;
        vector<pair<int, int>> con;
        for (int j{0}; j<n; j++){
            int a, x;
            cin >> a >> x;
            con.push_back(make_pair(a, x));
        }
        // maximum of type 1 and minimum of type 2
        int maxi_type1 = -1;
        int mini_type2 = INT_MAX;
        for (int j{0}; j<n; j++){
            if (con[j].first == 1){
                maxi_type1 = max(maxi_type1, con[j].second);
            }
            if (con[j].first == 2){
                mini_type2 = min(mini_type2, con[j].second);
            }
        }
        int legal_type3 = 0;
        for (int j{0}; j<n; j++){
            if (con[j].first == 3){
                if (con[j].second >= maxi_type1 and con[j].second <= mini_type2){
                    legal_type3++;
                }
            }
        }
        if (maxi_type1 > mini_type2){
            cout << 0 << endl;
        }
        else{
            cout << mini_type2-maxi_type1+1-legal_type3 << endl;
        }
    }
}