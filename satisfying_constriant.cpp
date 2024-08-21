#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

int main(){
    int no_of_test;
    cin >> no_of_test;
    for (int l{0}; l<no_of_test; l++){
        int no_of_constraint;
    ;    cin >> no_of_constraint;
        vector<long long int> type1;
        vector<long long int> type2;
        vector<long long int> type3;
        for (int i{0}; i<no_of_constraint; i++){
            int type;
            cin >> type;
            if (type == 1){
                long long int x;
                cin >> x;
                type1.push_back(x);
            }
            if (type == 2){
                long long int x;
                cin >> x;
                type2.push_back(x);
            }
            if (type == 3){
                long long int x;
                cin >> x;
                type3.push_back(x);
            }
        }
        long long int maxi = -1;
        for (int j{0}; j<type1.size(); j++){
            maxi = max(maxi, type1[j]);
        }
        long long int mini = pow(10, 9);
        for (int j{0}; j<type2.size(); j++){
            mini = min(mini, type2[j]);
        }
        int cnt = 0;
        for (int s{0}; s<type3.size(); s++){
            if (type3[s] >= maxi and type3[s] <= mini){
                cnt++;
            }
        }
        if (maxi <= mini){
            long long int k = abs(mini - maxi) + 1;
            k = (k - cnt);
            cout << k << endl;
        } 
        else {
            cout << 0 << endl;
        }        
    }
}