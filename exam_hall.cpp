#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

bool is_monitored(vector<bool> checker){
    for (long unsigned int i{1}; i<checker.size(); i++){
        if (checker[i] == false){
            return false;
        }
    }
    return true;
}

int main() {

    int n, m;
    cin >> n >> m;
    vector<int> student_position;
    for (int i{0}; i<n; i++){
        int x;
        cin >> x;
        student_position.push_back(x);
    }

    int maxi1 = -1;
    for (int i{0}; i<student_position.size(); i++){
        maxi1 = max(maxi1, student_position[i]);
    }
    vector<bool> student_seen(maxi1+1, false);
    

    for (int i{0}; i<student_position.size(); i++){
        student_seen[student_position[i]] = true;
    }

    vector<int> invigilator_position;
    for (int i{0}; i<m; i++){
        int x;
        cin >> x;
        invigilator_position.push_back(x);
    }
    

    int maxi2 = -1;
    for (int i{0}; i<invigilator_position.size(); i++){
        maxi2 = max(maxi2, invigilator_position[i]);
    }
    vector<bool> invigilator_watching(maxi2+1, false);
    
    for (int i{0}; i<invigilator_position.size(); i++){
        invigilator_watching[invigilator_position[i]] = true;
    }
    
    int ans = 100000;

    for (int k{1}; k<100000; k++){
        vector<bool> checker(maxi1+1, false);
        for (int j{1}; j<=maxi2; j++){
            if (invigilator_watching[j] == true){
               for (int s{max(1, j-k)}; s<=min(100000, j+k); s++){
                   checker[s] = true;
               }
            }
        }
        if (is_monitored(checker) == true){
            ans = min(ans, k);
        }
    }
    cout << ans;
}
