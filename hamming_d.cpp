#include<bits/stdc++.h>
using namespace std;


int totalHammingDistance(vector<int> nums) {
    int n = nums.size();
    int dist = 0;
    for(int i = 0 ; i < 32; i++){
        int one = 0;
        for(int j = 0 ; j < n ; j++){
            one += (nums[j]&1);  // Check if the current bit is 1
            nums[j] >>= 1;  // Right shift the number
        }
        dist += one*(n - one);  // Update the total Hamming distance
    }
    return dist;
}

int main(){
    int n;
    cin >> n;
    vector<int> num;
    for (int i{0}; i<n; i++){
        int x;
        cin >> x;
        num.push_back(x);
    }
    cout << totalHammingDistance(num);
}